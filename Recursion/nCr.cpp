#include<bits/stdc++.h>
using namespace std;

void combination(int pos, int ind, int res[], int n, int r)
{
    if(pos>r)
    {
        for(int i=1; i<=r; i++) printf("%d ", res[i]);
        printf("\n");
        return;
    }

    if(ind>n) return;
    res[pos] = ind;
    combination(pos+1, ind+1, res, n, r);
    combination(pos, ind+1, res, n, r);
}

int combinationNumber(int pos, int ind, int n, int r)
{
    if(pos>r) return 1;
    if(ind>n) return 0;

    int o1 = combinationNumber(pos+1, ind+1, n, r);
    int o2 = combinationNumber(pos, ind+1, n, r);
    return o1 + o2;
}

int main()
{
    int n, r;
    int res[100];
    scanf("%d %d", &n, &r);
    printf("Total combinations: %d\n", combinationNumber(1, 1, n, r));
    combination(1, 1, res, n, r);
    return 0;
}
