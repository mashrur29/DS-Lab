#include<iostream>
#include<algorithm>

int max_ind(int a[], int pos)
{
    if(pos==0) return pos;
    if(a[max_ind(a, pos-1)]>=a[pos]) return max_ind(a, pos-1);
    else return pos;
}

int main()
{
    int n, a[100], i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", max_ind(a, n-1)+1);
    return 0;
}


