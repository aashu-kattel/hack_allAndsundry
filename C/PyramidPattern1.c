#include<stdio.h>
main()
{
    int a,i,j,k;
    printf("Enter a number ::");
    scanf("%d",&a);
    for(i=a;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            printf("*");
        }
        printf(" ");
        for(k=0;k<i;k++)
        {
            printf("*");
        }
        printf("\n");
     }
}
