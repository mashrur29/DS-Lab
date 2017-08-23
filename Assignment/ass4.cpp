#include<stdio.h>

void print(int a[], int pos)
{
    if(pos<0) return;
    printf("%d ", a[pos]);
    print(a, pos-1);
}

int main()
{
    int n, a[100], i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    print(a, n-1);
    return 0;
}
