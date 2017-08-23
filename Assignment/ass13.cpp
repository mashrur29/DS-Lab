#include<iostream>
#include<algorithm>

int nCr(int n, int r)
{
    if(r==1) return n;
    if(n==r) return 1;
    return nCr(n-1, r)+nCr(n-1, r-1);
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", nCr(n, r));
    return 0;
}





