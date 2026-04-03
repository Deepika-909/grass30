#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char ch, str[50];
    FILE *fp = fopen("input.c", "r");

    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (isalpha(ch)) {
            int i = 0;
            str[i++] = ch;

            while (isalnum(ch = fgetc(fp)))
                str[i++] = ch;

            str[i] = '\0';

            fseek(fp, -1, SEEK_CUR); 

            printf("Identifier: %s\n", str);
        }

        else if (isdigit(ch)) {
            int i = 0;
            str[i++] = ch;

            while (isdigit(ch = fgetc(fp)) || ch == '.')
                str[i++] = ch;

            str[i] = '\0';

            fseek(fp, -1, SEEK_CUR);

            printf("Constant: %s\n", str);
        }

        else if (ch == '/' && (ch = fgetc(fp)) == '/') {
            printf("Comment: //");

            while ((ch = fgetc(fp)) != '\n' && ch != EOF)
                putchar(ch);

            printf("\n");
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
            printf("Operator: %c\n", ch);
    }

    fclose(fp);
    return 0;
}