#include<stdio.h>
#include<string.h>

void naive(char t[], char p[])
{
    int i,j,n,m;
    n=strlen(t);
    m=strlen(p);
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(t[i+j]!=p[j])
                break;
        }
        if(j==m)
            printf("pattern found at index %d.\n",i);
    }
}

int main()
{
    char t[100],p[100];
    printf("enter text: ");
    scanf("%s",t);
    printf("enter pattern: ");
    scanf("%s",p);
    naive(t,p);
    return 0;
}
