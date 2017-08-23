#include<iostream>
#include<algorithm>

int max_val(int a[], int pos)
{
    if(pos<0) return 0;
    return std::max(a[pos], max_val(a, pos-1));
}

int main()
{
    int n, a[100], i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", max_val(a, n-1));
    return 0;
}


