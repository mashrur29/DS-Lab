#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int lo, int mid, int hi)
{
    int n1, n2, i = 0, j = 0, k = lo;
    n1 = mid-lo+1;
    n2 = hi-mid;
    int L[100], R[100];

    for(i=0; i<n1; i++) L[i] = a[lo+i];
    for(i=0; i<n2; i++) R[i] = a[mid+1+i];
    i = 0;
    j = 0;

    while(1)
    {
        if(j>=n2&&i<n1 || i<n1&&j<n2&&L[i]<R[j])
        {
            a[k] = L[i];
            i++;
            k++;
        }
        else if(i>=n1&&j<n2 || i<n1&&j<n2&&L[i]>R[j])
        {
            a[k] = R[j];
            j++;
            k++;
        }
        else break;
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

int linear_search(int a[], int pos, int item,int n)
{
    if(pos>=n) return -1;
    if(a[pos]==item) return pos;
    return linear_search(a, pos+1, item, n);
}

int bin_search(int a[], int begin, int end, int item)
{
    if(begin>end) return -1;
    int mid=(begin+end)/2;
    if(a[mid]==item) return mid;

    if(a[mid]>item) return bin_search(a, begin, mid-1, item);
    else return bin_search(a, mid+1, end, item);
}

int main()
{
    int n, i, res, item, a[100], tp;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    printf("Enter the element you want to search: ");
    scanf("%d", &item);
    printf("Enter the Search algorithm you want to use:\n1. Linear Search\n2. Binary Search\n\n");

    scanf("%d", &tp);

    if(tp==1) res = linear_search(a, 0, item, n);
    else
    {
        merge_sort(a, 0, n-1);
        res = bin_search(a, 0, n-1, item);
    }

    if(res==-1) puts("Not Found");
    else printf("%d has been found at index %d\n", item, res+1);

    return 0;
}

/*

5
1 1 3 4 8


*/
