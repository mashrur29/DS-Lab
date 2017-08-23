#include<bits/stdc++.h>
using namespace std;

int partition_(int a[], int lo, int hi) {
  int pivot=a[hi];
  int i=lo-1;

  for(int j=lo; j<=hi-1; j++) {
    if(a[j]<=pivot) {
        i++;
        swap(a[i], a[j]);
    }
  }

  swap(a[i+1], a[hi]);
  return (i+1);
}

void quickSort(int a[], int lo, int hi) {
  if(lo<hi) {
    int pi=partition_(a, lo, hi);
    quickSort(a, lo, pi-1);
    quickSort(a, pi+1, hi);
  }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
