#include<bits/stdc++.h>
using namespace std;

struct graph
{
    vector<int>adj[11];
    int a[11][11], n, d[11], col[11];

    graph()
    {
        memset(col, 0, sizeof(col));
        memset(a, 0, sizeof(a));
        for(int i=0; i<11; i++) adj[i].clear();
    }

    void input(int u, int v)
    {
        a[u][v] = 1;
        a[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isEdge(int u, int v)
    {
        return (a[u][v]==1 || a[v][u]==1);
    }

    bool isEdge_(int u, int v)
    {
        for(auto &x: adj[u])
        {
            if(x==v) return true;
        }

        for(auto &x: adj[v])
        {
            if(x==u) return true;
        }

        return false;
    }

    void bfs(int src)
    {
        queue<int> q;
        d[src] = 0;
        col[src] = 0;
        q.push(src);

        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            for(auto &u: adj[x])
            {
                if(d[u]==-1)
                {
                    col[u] = 1 - col[x];
                    d[u] = d[x] + 1;
                    q.push(u);
                }
            }

        }

    }

    void dfs(int src)
    {

        for(auto &u: adj[src])
        {
            if(d[u]==0)
            {
                d[u] = 1;
                dfs(u);
            }
        }

        d[src] = 1;
    }

    bool isPath(int u, int v)
    {
        memset(d, 0, sizeof(d));
        dfs(u);
        return d[v]==1;
    }

    int shortest(int u, int v)
    {
        memset(d, -1, sizeof(d));
        bfs(u);
        return d[v];
    }

    bool isBipartite()
    {
        memset(col, 0, sizeof(col));
        memset(d, -1, sizeof(d));
        for(int i=1; i<=n; i++)
        {
            if(d[i]==-1) bfs(i);
        }

        for(int i=1; i<=n; i++)
        {
            for(auto &x: adj[i])
            {
                if(col[i]==col[x]) return false;
            }
        }

        return true;
    }

};

int main()
{
    int m, tp;
    graph g;

    puts("\t\t\t\t**********Input Graph**************\n");

    scanf("%d %d", &g.n, &m);

    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g.input(u, v);
    }

    puts("\n\n\t\t\t\t ************* Menu **************\n\n");
    puts("\t\t  1. Press 1 to detect edge between u and v using matrix.");
    puts("\t\t  2. Press 2 to detect edge between u and v using vector.");
    puts("\t\t  3. Press 3 to detect path between u and v.");
    puts("\t\t  4. Press 4 to find shortest path between u and v.");
    puts("\t\t  5. Press 5 to find whether the graph is bi-partite or not.\n\n");

    while(scanf("%d", &tp)==1)
    {
        int u, v;

        if(tp==1)
        {
            scanf("%d %d", &u, &v);
            if(g.isEdge(u, v)) printf("There is an edge between %d and %d\n", u, v);
            else printf("There is no edge between %d and %d\n", u, v);
        }
        else if(tp==2)
        {
            scanf("%d %d", &u, &v);
            if(g.isEdge_(u, v)) printf("There is an edge between %d and %d\n", u, v);
            else printf("There is no edge between %d and %d\n", u, v);
        }
        else if(tp==3)
        {
            scanf("%d %d", &u, &v);
            if(g.isPath(u, v)) printf("There is a path between %d and %d\n", u, v);
            else printf("There is no path between %d and %d\n", u, v);
        }
        else if(tp==4)
        {
            scanf("%d %d", &u, &v);
            int res = g.shortest(u, v);
            if(res!=-1) printf("The shortest path from %d to %d is %d\n", u, v, res);
            else printf("There is no path between %d and %d\n", u, v);
        }
        else if(tp==5)
        {
            if(g.isBipartite()) printf("The graph is bi-partite\n");
            else printf("The graph is not bi-partite\n");
        }
        else break;
    }

    return 0;
}
