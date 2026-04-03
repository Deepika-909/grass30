#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char *input;
int i = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();
void error();

void error() {
    printf("Syntax Error at position %d\n", i);
    exit(1);
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[i] == '+') {
        i++;
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[i] == '*') {
        i++;
        F();
        Tprime();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else
            error();
    }
    else if (isalpha(input[i])) {
        i++;
    }
    else {
        error();
    }
}

int main() {
    char expr[100];

    printf("Enter expression: ");
    scanf("%s", expr);

    input = expr;
    i = 0;

    E();

    if (input[i] == '\0')
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");

    return 0;
}