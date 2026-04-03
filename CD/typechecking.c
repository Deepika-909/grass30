#include <stdio.h>
int main()
{
    int n, i, k, flag = 0;
    char vari[15], typ[15], expr[50], ch;
    printf("Enter number of variables: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter variable %d: ", i + 1);
        scanf(" %c", &vari[i]);

        printf("Enter type (i=int, f=float): ");
        scanf(" %c", &typ[i]);
    }
    printf("Enter expression (end with $): ");
    i = 0;

    while((ch = getchar()) != '$')
    {
        if(ch != '\n')
            expr[i++] = ch;
    }
    expr[i] = '\0';

    k = i;
    for(i = 0; i < k; i++)
    {
        if(expr[i] == '/')
        {
            flag = 1;
            break;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(expr[0] == vari[i])
        {
            if(flag == 1)
            {
                if(typ[i] == 'f')
                    printf("\nDatatype is correctly defined!\n");
                else
                    printf("\nError: %c must be float type!\n", vari[i]);
            }
            else
                printf("\nDatatype is correctly defined!\n");

            break;
        }
    }

    return 0;
}