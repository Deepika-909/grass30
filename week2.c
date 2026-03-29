#include <stdio.h>
int main()
{
    char *str = "Hello World";
    int i;

    printf("Original String: %s\n\n", str);

    printf("AND with 127:\n");
    for (i = 0; str[i] != '\0'; i++)
    {
        int result = str[i] & 127;
        printf("%c -> %c (ASCII %d)\n", str[i], result, result);
    }

    printf("\nXOR with 127:\n");
    for (i = 0; str[i] != '\0'; i++)
    {
        int result = str[i] ^ 127;
        printf("%c -> %c (ASCII %d)\n", str[i], result, result);
    }

    printf("\nOR with 127:\n");
    for (i = 0; str[i] != '\0'; i++)
    {
        int result = str[i] | 127;
        printf("%c -> %c (ASCII %d)\n", str[i], result, result);
    }

    return 0;
}