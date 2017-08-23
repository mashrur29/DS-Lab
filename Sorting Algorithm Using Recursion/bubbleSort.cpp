#include<bits/stdc++.h>
using namespace std;

void bubble_helper(int a[], int pos)
{
    if(pos<=0) return;
    if(a[pos]<a[pos-1]) swap(a[pos], a[pos-1]);
    bubble_helper(a, pos-1);
}

void bubble_sort(int a[], int pos)
{
    if(pos<=0) return;
    bubble_sort(a, pos-1);
    bubble_helper(a, pos);
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
    bubble_sort(a, n-1);
    printArray(a, n);
}
