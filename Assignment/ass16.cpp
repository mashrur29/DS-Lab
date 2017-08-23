#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int lo, int mid, int hi)
{
    int n1, n2, k = lo, i, j, inf=1e8;
    n1 = mid-lo+1;
    n2 = hi-mid;
    int L[100], R[100];
    L[n1] = inf;
    R[n2] = inf;

    for(i=0; i<n1; i++) L[i] = a[lo+i];
    for(i=0; i<n2; i++) R[i] = a[mid+1+i];
    i = 0;
    j = 0;

    while(i<n1 || j<n2)
    {
        if(L[i]<R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
        }
    }
}

void merge_sort(int a[], int lo, int hi)
{
    if(lo<hi)
    {
        int mid = (lo+hi)/2;
        merge_sort(a, lo, mid);
        merge_sort(a, mid+1, hi);
        merge(a, lo, mid, hi);
    }
}

int main()
{
    int n, i, a[100];

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    merge_sort(a, 0, n-1);

    for(i=0; i<n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
