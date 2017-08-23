#include<bits/stdc++.h>
using namespace std;

int select_max(int a[], int pos, int res)
{
    if(pos<0) return res;
    if(a[pos]>a[res]) res=pos;
    return select_max(a, pos-1, res);
}

void selection_sort(int a[], int n)
{
    if(n<0) return;
    int res = select_max(a, n-1, n);

    if(res!=n)
    {
        int temp = a[n];
        a[n] = a[res];
        a[res] = temp;
    }

    selection_sort(a, n-1);
}

int main()
{
    int n, i, a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    selection_sort(a, n-1);
    for(i=0; i<n; i++) cout<<a[i]<<" ";
}

/*

7
8 5 3 2 4 8 7

*/
