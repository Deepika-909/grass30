#include <stdio.h>
int main()
{
    int n, i, j, k, div =0, ffound = 0;
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
            div = 1;
            break;
        }
    }

    for(i = 0; expr[i] != '\0'; i++) {
        if(isalpha(expr[i])) {
            for(j = 0; j < n; j++) {
                if(expr[i] == vari[j]) {
                    if(typ[j] == 'f')
                        ffound = 1;
                }
            }
        }
    }

    // Final decision
    if(ffound == 0 && div == 1)
        printf("Error: Expression requires float type\n");
    else
        printf("Datatype is correct\n");
    return 0;
}
