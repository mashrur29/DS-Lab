#include<stdio.h>
#include<string.h>

int isPalin(char a[], int first, int last)
{
    if(first>=last) return 1;
    if(a[first]!=a[last]) return 0;
    return isPalin(a, first+1, last-1);
}

int main()
{
    char a[100];
    scanf("%s", a);
    if(isPalin(a, 0, strlen(a)-1)) puts("YES");
    else puts("NO");
    return 0;
}
