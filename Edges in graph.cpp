#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
};

struct Linked_list
{
    node *head=NULL;

    int Last_()
    {
        node *p=(node *)malloc(sizeof(node));
        p=head;
        while(head->next!=NULL)
        {
            head=head->next;
        }
        int t=head->val;
        head=p;
        return t;
    }

    int Top_of_list()
    {
        return head->val;
    }

    void print_()
    {
        node *p=(node *)malloc(sizeof(node));
        p=head;
        while(head->next!=NULL)
        {
            printf("%d ",head->val);
            head=head->next;
        }
        printf("%d\n",head->val);
        head=p;
    }

    void insert_last(int x)
    {
        node *a=(node *)malloc(sizeof(node));
        a->val=x;
        a->next=NULL;
        if(head==NULL)
        {
            head=a;
            return;
        }

        node *p=(node *)malloc(sizeof(node));
        p=head;

        while(head->next!=NULL)
        {
            head=head->next;
        }

        head->next=a;
        head=p;
    }

    void insert_first(int x)
    {
        node *a=(node *)malloc(sizeof(node));
        a->val=x;
        a->next=head;
        head=a;
    }

    void delete_first()
    {
        head=head->next;
    }

    void delete_last()
    {
        node *t=(node *)malloc(sizeof(node));
        node *a=(node *)malloc(sizeof(node));
        a=head;

        while(head->next!=NULL)
        {
            t=head;
            head=head->next;
        }
        t->next=NULL;
        head=a;
    }

};

int d[101], tm_, tree_edge, cross, back_, front_;
char vis[101];
Linked_list adj[100];

void reset()
{
    for(int i=0; i<101; i++)
    {
        d[i] = 0;
        vis[i] = 'W';
    }
    tm_ = 1;
    cross = 0;
    tree_edge = 0;
    back_ = 0;
    front_ = 0;
}


void dfs(int u)
{
    vis[u] = 'G';
    d[u] = tm_++;
    node *it=adj[u].head;

    while(it!=NULL)
    {
        int v = it->val;

        if(vis[v]=='G') back_++;
        else if(vis[v]=='B')
        {
            if(d[u]<d[v]) front_++;
            else cross++;
        }
        else tree_edge++;

        if(vis[v]=='W')
        {
            dfs(v);
        }

        it = it->next;
    }

    vis[u] = 'B';
}

int main()
{
    reset();
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].insert_last(v);
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]=='W') dfs(i);
    }

    printf("Cross: %d\nBack: %d\nFront: %d\n", cross, back_, front_);
    return 0;
}
