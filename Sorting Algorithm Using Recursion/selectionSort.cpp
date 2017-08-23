#include<bits/stdc++.h>
using namespace std;

int selection_helper(int a[], int i, int n, int res)
{
    if(i>=n) return res;
    if(a[i]<a[res]) res = i;
    return selection_helper(a, i+1, n, res);
}

void selection_sort(int a[], int i, int n)
{
    if(i>=n) return;
    if(selection_helper(a, i, n, i)!=i) swap(a[selection_helper(a, i, n, i)], a[i]);
    selection_sort(a, i+1, n);
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
    selection_sort(a, 0, n);
    printArray(a, n);
    return 0;
}
