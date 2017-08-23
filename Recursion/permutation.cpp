#include<bits/stdc++.h>
using namespace std;

void permutation(int taken[], int pos, int res[], int n)
{
    if(pos>n)
    {
        for(int i=1; i<=n; i++) printf("%d ", res[i]);
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            taken[i] = 1;
            res[pos] = i;
            permutation(taken, pos+1, res, n);
            taken[i] = 0;
        }
    }
}

int permutationNumber(int taken[], int pos, int n)
{
    if(pos>n) return 1;

    int res = 0;

    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            taken[i] = 1;
            res += permutationNumber(taken, pos+1, n);
            taken[i] = 0;
        }
    }

    return res;
}

int main()
{
    int n;
    int res[100], taken[100];
    memset(taken, 0, sizeof(taken));

    scanf("%d", &n);

    printf("Total permutations: %d\n", permutationNumber(taken, 1, n));
    memset(taken, 0, sizeof(taken));
    permutation(taken, 1, res, n);

    return 0;
}
