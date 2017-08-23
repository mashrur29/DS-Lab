#include<iostream>
#include<algorithm>

int sum(int a[], int pos) {
   if(pos<0) return 0;
   else return a[pos]+sum(a, pos-1);
}

int main()
{
    int n, a[100], i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", sum(a, n-1));
    return 0;
}





