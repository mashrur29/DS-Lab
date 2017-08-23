#include<iostream>
#include<algorithm>
int val;

int find_(int a[], int low, int high)
{
    int mid = (low + high)/2;
    if(a[mid]==val) return mid;
    if(low>high) return -1;
    if(a[mid]>val) return find_(a, low, mid-1);
    else return find_(a, mid+1, high);
}

int main()
{
    int n, a[100], i;
    scanf("%d %d", &n, &val);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", find_(a, 0, n-1));
    return 0;
}




