#include<bits/stdc++.h>
using namespace std;

void merge_(int a[], int lo, int mid, int hi)
{
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    int L[100], R[100], inf = 1e8;
    L[n1] = R[n2] = inf;

    for(int i=0; i<n1; i++) L[i] = a[lo+i];
    for(int i=0; i<n2; i++) R[i] = a[mid+1+i];

    int i = 0, j = 0, k = lo;

    while(i<n1 || j<n2)
    {
        if(L[i]<R[j])
        {
            a[k++] = L[i++];
        }
        else a[k++] = R[j++];
    }

}

void merge_sort(int a[], int lo, int hi)
{
    if(lo<hi)
    {
        int mid = (lo+hi)/2;
        merge_sort(a, lo, mid);
        merge_sort(a, mid+1, hi);
        merge_(a, lo, mid, hi);
    }
}

void printArray(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    puts("");
}

int main()
{
    int a[] = {1, 2, 9, -2, 1, 0};
    int n = 6;
    merge_sort(a, 0, n-1);
    printArray(a, n);
}
