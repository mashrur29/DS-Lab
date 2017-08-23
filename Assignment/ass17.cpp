#include<stdio.h>

void bubble_sort_(int a[], int pos, int n)
{
    if(pos>n-1) return;

    if(a[pos]>a[pos+1])
    {

        int temp = a[pos];
        a[pos] = a[pos+1];
        a[pos+1] = temp;

    }

    bubble_sort_(a, pos+1, n);
}

void bubble_sort(int a[], int n)
{
    if(!n) return;
    bubble_sort_(a, 0, n-1);
    bubble_sort(a, n-1);
}

int main()
{
    int n, i, a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    bubble_sort(a, n);
    for(i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}


/*

7
8 5 3 2 4 8 7

*/
