#include<stdio.h>
#include<cstring>
void generate(int pos, int taken[], int n, int res[], int ara[]);


void move_(int i, int pos, int taken[], int n, int res[], int ara[])
{
    if(i>n) return;
    if(!taken[i])
    {
        taken[i]=1;
        res[pos]=ara[i];
        generate(pos+1, taken, n, res, ara);
        taken[i]=0;
    }
    move_(i+1, pos, taken, n, res, ara);
}

void generate(int pos, int taken[], int n, int res[], int ara[])
{
    if(pos>n)
    {
        for(int i=1; i<=n; i++) printf("%d ", res[i]);
        puts("");
        return;
    }
    move_(1, pos, taken, n, res, ara);
}

void combination(int res[], int n, int r, int pos, int ind)
{
    if(pos>r)
    {
        int taken[100], r_[100];
        memset(taken, 0, sizeof(taken));
        generate(1, taken, r, r_, res);
        for(int i=1; i<=r; i++) printf("%d ", res[i]);
        puts("");
        return;
    }

    if(ind>n) return;
    res[pos]=ind;
    combination(res, n, r, pos+1, ind+1);
    combination(res, n, r, pos, ind+1);
}

int main()
{
    int n, i, r, res[100];
    scanf("%d %d", &n, &r);
    combination(res, n, r, 1, 1);
}
