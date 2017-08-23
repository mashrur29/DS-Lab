#include<iostream>
#include<algorithm>

int gcd(int a, int b)
{
    if(!a) return b;
    if(!b) return a;
    return gcd(b, a%b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}






