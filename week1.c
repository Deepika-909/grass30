#include<stdio.h>
int main()
{
    char *str="Hello World";
    int i;
    char result;
    printf("XOR Operation with 0\n\n");
    for(i=0;str[i]!='\0'; i++)
    {
    result=str[i]^0;
    printf("'%c' XOR 0 = '%c'\n",str[i],result);
    }
    return 0;
}