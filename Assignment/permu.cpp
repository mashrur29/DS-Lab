#include<stdio.h>
void generate(int pos, int taken[], int n, int res[]);


void move_(int i, int pos, int taken[], int n, int res[])
{
    if(i>n) return;
    if(!taken[i])
    {
        taken[i]=1;
        res[pos]=i;
        generate(pos+1, taken, n, res);
        taken[i]=0;
    }
    move_(i+1, pos, taken, n, res);
}

void generate(int pos, int taken[], int n, int res[])
{
    if(pos>n)
    {
        for(int i=1; i<=n; i++) printf("%d ", res[i]);
        puts("");
        return;
    }
    move_(1, pos, taken, n, res);
}

int main()
{
    int n, i, res[100], taken[100];
    scanf("%d", &n);
    for(i=1; i<=n; i++) taken[i]=0;
    generate(1, taken, n, res);
    return 0;
}
