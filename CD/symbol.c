#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct table {
    char var[10];
    int value;
};

struct table tbl[20];
int i, j, n = 0;

void create();
void modify();
int search(char variable[], int n);
void insert();
void display();

int main() {
    int ch, result;
    char v[10];

    do {
        printf("\n1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: modify(); break;
            case 4:
                printf("Enter variable to search: ");
                scanf("%s", v);
                result = search(v, n);
                if(result == -1) printf("Not found\n");
                else printf("Loc: %d  Value: %d\n", result+1, tbl[result].value);
                break;
            case 5: display(); break;
            case 6: exit(0);
        }
    } while(ch != 6);

    return 0;
}

void create() {
    printf("How many entries? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        while(1) {
            printf("Enter variable and value: ");
            scanf("%s %d", tbl[i].var, &tbl[i].value);

            if(tbl[i].var[0] >= '0' && tbl[i].var[0] <= '9') continue;

            for(j = 0; j < i; j++)
                if(strcmp(tbl[i].var, tbl[j].var) == 0) break;

            if(j == i) break;
        }
    }
}

void insert() {
    if(n >= 20) return;

    while(1) {
        printf("Enter variable and value: ");
        scanf("%s %d", tbl[n].var, &tbl[n].value);

        if(tbl[n].var[0] >= '0' && tbl[n].var[0] <= '9') continue;

        for(j = 0; j < n; j++)
            if(strcmp(tbl[n].var, tbl[j].var) == 0) break;

        if(j == n) break;
    }
    n++;
}

void modify() {
    char variable[10];
    int result;

    printf("Enter variable to modify: ");
    scanf("%s", variable);

    result = search(variable, n);
    if(result == -1) {
        printf("Variable not found\n");
        return;
    }

    printf("Enter new variable and new value: ");
    scanf("%s %d", tbl[result].var, &tbl[result].value);
}

int search(char variable[], int n) {
    for(i = 0; i < n; i++)
        if(strcmp(tbl[i].var, variable) == 0)
            return i;

    return -1;
}

void display() {
    printf("\nVAR\tVALUE\n");
    for(i = 0; i < n; i++)
        printf("%s\t%d\n", tbl[i].var, tbl[i].value);
}
