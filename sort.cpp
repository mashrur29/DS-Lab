#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int a[], int n)  // O(n^2)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

}

void insertion_sort(int a[], int n)  // O(n^2)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        j=i;
        while(j>0 && a[j-1]>a[j])
        {
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j=j-1;
        }
    }

}

void selection_sort(int a[], int n) // O(n^2)
{
    int i, j;

    for(int i=0; i<n-1; i++)
    {
        int res=i;

        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[res]) res=j;
        }

        if(res!=i)
        {
            int temp=a[i];
            a[i]=a[res];
            a[res]=temp;
        }
    }

}

void counting_sort(int a[], int n)  // O(n)
{
    int cnt[1000], i, b[1000];

    for(i=0; i<100; i++) cnt[i]=0;
    for(i=0; i<n; i++) cnt[a[i]]++;
    for(i=1; i<100; i++) cnt[i]+=cnt[i-1];

    for(i=0; i<n; i++)
    {

        if(cnt[a[i]]>0)
        {
            b[cnt[a[i]]]=a[i];
            cnt[a[i]]--;
        }

    }
    for(i=1; i<=n; i++) a[i-1]=b[i];
}

int main()
{
    int a[100], n, i;

    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    selection_sort(a, n);

    for(i=0; i<n; i++)
    {
        printf("%d",a[i]);
        if(i<n-1) printf(" ");
        else printf("\n");
    }

    return 0;
}

/*

6
4 5 2 1 3 0

*/
