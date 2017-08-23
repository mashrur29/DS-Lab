#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i) {
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;

  if(left<n && a[left]>a[largest]) largest=left;
  if(right<n && a[right]>a[largest]) largest=right;

  if(largest!=i) {
    swap(a[i], a[largest]);
    heapify(a, n, largest);
  }
}

void heapSort(int a[], int n) {
  for(int i=n/2; i>=0; i--) heapify(a, n, i);

  for(int i=n-1; i>=0; i--) {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}
