#include <stdio.h>
#include <ctype.h>

void FIRST(char);

char prod[10][10], first[10];
int count, n;

int present(char c) {
    for (int i = 0; i < n; i++)
        if (first[i] == c) return 1;
    return 0;
}

int main() {
    char c;
    int choice;

    printf("How many productions? : ");
    scanf("%d", &count);

    printf("Enter productions (use $ for epsilon):\n");
    for (int i = 0; i < count; i++)
        scanf("%s", prod[i]);

    do {
        n = 0;

        printf("\nEnter non-terminal: ");
        scanf(" %c", &c);

        FIRST(c);

        printf("FIRST(%c) = { ", c);
        for (int i = 0; i < n; i++)
            printf("%c ", first[i]);
        printf("}\n");

        printf("Press 1 to continue: ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}

// FIRST logic
void FIRST(char c) {
    if (!isupper(c)) {
        if (!present(c))
            first[n++] = c;
        return;
    }

    for (int i = 0; i < count; i++) {
        if (prod[i][0] == c) {

            if (prod[i][2] == '$') {         
                if (!present('$'))
                    first[n++] = '$';
            }
            else if (!isupper(prod[i][2])) { 
                if (!present(prod[i][2]))
                    first[n++] = prod[i][2];
            }
            else {                          
                FIRST(prod[i][2]);
            }
        }
    }
}