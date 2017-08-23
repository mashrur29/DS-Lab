#include<bits/stdc++.h>
using namespace std;

void helper(int a[], int j)
{
    if(!j) return;

    if(a[j-1]>a[j])
    {
        swap(a[j], a[j-1]);
        helper(a, j-1);
    }
}

void insertion_sort(int a[], int pos, int n)
{
    if(pos>=n) return;
    helper(a, pos);
    insertion_sort(a, pos+1, n);
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, 0, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}
