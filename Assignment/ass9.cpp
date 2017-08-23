#include<iostream>
#include<algorithm>

int find_(int a[], int n)
{
    if(*a==n) return 1;
    if(*a==sizeof(a)) return -1;
    if(find_(a+1, n)!=-1) return 1+find_(a+1, n);
    else return -1;
}

int main()
{
    int n, a[100], i, val;
    scanf("%d %d", &n, &val);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", find_(a, val));
    return 0;
}



