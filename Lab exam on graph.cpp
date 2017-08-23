#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int d[101], par[101];
bool cycle;
char vis[101];
int n, m;
stack<int> st;

void reset()
{

    for(int i=0; i<101; i++)
    {
        vis[i] = 'W';
        par[i] = -1;
        d[i] = -1;
    }

    cycle = false;
}

void bfs(int src)
{
    cycle = false;
    queue<int> q;
    q.push(src);
    d[src] = 0;
    par[src] = -1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto &u: adj[x])
        {
            if(d[u]==-1)
            {
                par[u] = x;
                d[u] = d[x] + 1;
                q.push(u);
            }
        }

    }

}

void dfs(int u)
{
    vis[u] = 'G';

    for(auto &x: adj[u])
    {
        if(vis[x]=='G') cycle = true;
        else if(vis[x]=='W') dfs(x);
    }

    st.push(u);
    vis[u] = 'B';
}

void printPath(int u)
{
    if(u==-1) return;
    printPath(par[u]);
    printf("%d ", u);
}

int main()
{
    int tp;
    puts("\t\t\t\t**********Input Graph**************\n");

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    puts("\n\n\t\t\t\t ************* Menu **************\n\n");
    puts("\t\t  1. Press 1 to find shortest path length between u and v.");
    puts("\t\t  2. Press 2 to find shortest path between u and v.");
    puts("\t\t  3. Press 3 to find topological order of graph.");
    puts("\t\t  4. Press 4 to find whether the graph is a tree.\n\n");

    while(scanf("%d", &tp)==1)
    {
        reset();
        int src, dst;
        if(tp==1)
        {
            scanf("%d %d", &src, &dst);
            for(int i=1; i<=n; i++)
            {
                if(d[i]==-1) bfs(i);
            }
            if(d[dst]==-1) puts("No path present");
            else printf("The shortest path from %d to %d is: %d\n", src, dst, d[dst]);
        }
        else if(tp==2)
        {
            scanf("%d %d", &src, &dst);
            for(int i=1; i<=n; i++)
            {
                if(d[i]==-1) bfs(i);
            }
            if(d[dst]==-1) puts("No path present");
            else
            {
                printf("The shortest path from %d to %d is: ", src, dst);
                printPath(dst);
                puts("");
            }
        }
        else if(tp==3)
        {
            for(int i=1; i<=n; i++)
            {
                if(vis[i]=='W') dfs(i);
            }
            if(cycle) printf("No topological order present\n");
            else
            {
                printf("The required order is: ");
                while(!st.empty())
                {
                    printf("%d ", st.top());
                    st.pop();
                }
                puts("");
            }
        }
        else
        {
            int cmp=0;
            cycle = false;
            for(int i=1; i<=n; i++)
            {
                if(vis[i]=='W')
                {
                    dfs(i);
                }
            }

            reset();
            cycle = false;
            while(!st.empty())
            {
                int x = st.top();
                st.pop();
                if(vis[x]=='W')
                {
                    cmp++;
                    dfs(x);
                }
            }

            if(cmp==1 && !cycle) printf("The graph is a tree\n");
            else printf("The graph is not a tree\n");
        }
    }

    return 0;
}
