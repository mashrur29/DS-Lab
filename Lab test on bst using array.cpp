#include<stdio.h>
#include<stdlib.h>


struct BST
{
    int a[1001],taken[1001];
    int sz;

    BST()
    {
        sz = 0;
        for(int i=0; i<1001; i++) a[i] = -1;
        for(int i=0; i<1001; i++) taken[i] = -1;
    }

    int left(int n)
    {
        return 2*n;
    }

    int right(int n)
    {
        return 2*n+1;
    }

    void insert_(int v, int k)
    {
        // printf("%d\n", k);
        if(a[k]==v || k>1000) return;
        if(sz==0)
        {
            a[1] = v;
            sz++;
            taken[1]++;
            return;
        }
        int L = left(k);
        int R = right(k);

        if(v<a[k])
        {
            if(taken[L]==-1)
            {
                a[L] = v;
                sz++;
                taken[L]++;
                return;
            }
            else insert_(v, L);
        }
        else
        {
            if(taken[R]==-1)
            {
                a[R] = v;
                sz++;
                taken[R]++;
                return;
            }
            else insert_(v, R);
        }
    }

    void search_(int v, int k)
    {
        if(a[k]==v)
        {
            puts("Found");
            return;
        }
        if(taken[k]==-1)
        {
            puts("NOT FOUND");
            return;
        }
        if(v<a[k]) search_(v, left(k));
        else search_(v, right(k));
    }

    void inOrder(int k)
    {
        if(taken[k]==-1) return;
        int L = left(k);
        int R = right(k);
        inOrder(left(k));
        printf("%d ", a[k]);
        inOrder(right(k));
    }

};

int main()
{
    BST L;
    int tp, x;

    puts("\n\n\t ************* Menu **************\n\n");
    puts("\t  1. Press 1 to insert.");
    puts("\t  2. Press 2 to search.");
    puts("\t  3. Press 3 to print inOrder.\n\n");

    while(scanf("%d", &tp)==1)
    {
        if(tp==1)
        {
            scanf("%d", &x);
            L.insert_(x, 1);
        }
        else if(tp==2)
        {
            scanf("%d", &x);
            L.search_(x, 1);
        }
        else
        {
            L.inOrder(1);
            puts("");
        }
    }

    return 0;
}
