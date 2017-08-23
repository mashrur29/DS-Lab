#include<stdio.h>

void combination(int res[], int n, int r, int pos, int ind)
{
    if(pos>r)
    {
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
