#include<stdio.h>
#include<stdlib.h>

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

struct Queue
{
    Linked_list L;
    int c=0;

    void push(int x)
    {
        c++;
        L.insert_last(x);
    }

    int top()
    {
        return L.Top_of_list();
    }

    int pop()
    {
        if(!c)
        {
            puts("ERR");
            return -1;
        }
        c--;
        int t=L.Top_of_list();
        L.delete_first();
        return t;
    }

    void print_()
    {
        if(!c) puts("Empty");
        else L.print_();
    }

    int isEmpty()
    {
        if(!c) return 1;
        else return 0;
    }

};

Linked_list adj[100];
int d[100];

void bfs(int src) {
   Queue q;
   q.push(src);
   d[src]=0;

   while(!q.isEmpty()) {
     int x = q.top();
     q.pop();

     node *it=adj[x].head;

     while(it!=NULL) {
        int v = it->val;
        if(d[v]==-1) {
            d[v]=d[x]+1;
            q.push(v);
        }

        it = it->next;
     }

   }

}

int main() {
  for(int i=0; i<100; i++) d[i]=-1;

  adj[1].insert_last(2);
  adj[2].insert_last(1);

  adj[2].insert_last(3);
  adj[3].insert_last(2);

  adj[1].insert_last(3);
  adj[3].insert_last(1);

  adj[2].insert_last(4);
  adj[4].insert_last(2);

  bfs(1);

  printf("%d\n", d[1]);
}
