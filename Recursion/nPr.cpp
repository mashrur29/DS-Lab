#include<bits/stdc++.h>
using namespace std;

void permutation(int taken[], int pos, int res[], int n, int r)
{
    if(pos>r)
    {
        for(int i=1; i<=r; i++) printf("%d ", res[i]);
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            taken[i] = 1;
            res[pos] = i;
            permutation(taken, pos+1, res, n, r);
            taken[i] = 0;
        }
    }
}

int permutationNumber(int taken[], int pos, int n, int r)
{
    if(pos>r) return 1;

    int res = 0;

    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            taken[i] = 1;
            res += permutationNumber(taken, pos+1, n, r);
            taken[i] = 0;
        }
    }

    return res;
}

int main()
{
    int n, r;
    int res[100], taken[100];
    memset(taken, 0, sizeof(taken));

    scanf("%d %d", &n, &r);

    printf("Total permutations: %d\n", permutationNumber(taken, 1, n, r));
    memset(taken, 0, sizeof(taken));
    permutation(taken, 1, res, n, r);

    return 0;
}
