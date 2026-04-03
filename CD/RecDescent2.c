#include <stdio.h>
#include <stdlib.h>

const char *input;
int pos = 0;

char lookahead() {
    return input[pos];
}

// error
void error() {
    printf("Error at position %d\n", pos);
    exit(1);
}

int S();
int L();

// S → a | (L)
int S() {
    if (lookahead() == 'a') {
        pos++;
        return 1;
    }
    else if (lookahead() == '(') {
        pos++;

        if (!L()) error();

        if (lookahead() == ')') {
            pos++;
            return 1;
        }
        else error();
    }
    return 0;
}

// L → S (, S)*
int L() {
    if (!S()) return 0;

    while (lookahead() == ',') {
        pos++;
        if (!S()) error();
    }
    return 1;
}

int main() {
    char buffer[100];

    printf("Enter input string: ");
    scanf("%s", buffer);

    input = buffer;
    pos = 0;

    if (S() && input[pos] == '\0')
        printf("String is valid\n");
    else
        error();

    return 0;
}