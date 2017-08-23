#include<stdio.h>

int odd(int a[], int pos)
{
    if(pos<0) return 0;
    if(a[pos]&1) return 1+odd(a, pos-1);
    else return odd(a, pos-1);
}

int main()
{
    int n, a[100], i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", odd(a, n-1));
    return 0;
}

