#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char firstE[MAX], firstEp[MAX];
char firstT[MAX], firstTp[MAX];
char firstF[MAX];

int found(char *set, char c) {
    for (int i = 0; set[i]; i++) {
        if (set[i] == c) return 1;
    }
    return 0;
}

void add(char *set, char c) {
    if (!found(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

void computeFirstF() {
    // F → (E) | ID
    add(firstF, '(');  // from (E)
    add(firstF, 'i');  // 'i' stands for ID
}

void computeFirstTprime() {
    // T’ → * F T’ | ε
    add(firstTp, '*');
    add(firstTp, 'e'); // 'e' denotes ε
}

void computeFirstT() {
    // T → F T’
    for (int i = 0; firstF[i]; i++)
        add(firstT, firstF[i]);
}

void computeFirstEprime() {
    // E’ → + T E’ | ε
    add(firstEp, '+');
    add(firstEp, 'e'); // ε
}

void computeFirstE() {
    // E → T E’
    for (int i = 0; firstT[i]; i++)
        add(firstE, firstT[i]);
}

int main() {
    // Initialize sets
    strcpy(firstE, "");
    strcpy(firstEp, "");
    strcpy(firstT, "");
    strcpy(firstTp, "");
    strcpy(firstF, "");

    // Compute in order: F -> T’ -> T -> E’ -> E
    computeFirstF();
    computeFirstTprime();
    computeFirstT();
    computeFirstEprime();
    computeFirstE();

    printf("FIRST(F)  = { ");
    for (int i = 0; firstF[i]; i++) printf("%c ", firstF[i]);
    printf("}\n");

    printf("FIRST(T’) = { ");
    for (int i = 0; firstTp[i]; i++) printf("%c ", firstTp[i]);
    printf("}\n");

    printf("FIRST(T)  = { ");
    for (int i = 0; firstT[i]; i++) printf("%c ", firstT[i]);
    printf("}\n");

    printf("FIRST(E’) = { ");
    for (int i = 0; firstEp[i]; i++) printf("%c ", firstEp[i]);
    printf("}\n");

    printf("FIRST(E)  = { ");
    for (int i = 0; firstE[i]; i++) printf("%c ", firstE[i]);
    printf("}\n");

    return 0;
}
