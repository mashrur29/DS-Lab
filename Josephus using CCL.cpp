#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    node *next;
};

struct Circular_linked_list
{
    node *head=NULL;
    node *tail=NULL;
    int cnt;

    Circular_linked_list()
    {
        cnt=0;
    }

    void print()
    {
        node *p=(node *)malloc(sizeof(node));

        if(!cnt)
        {
            puts("Empty list");
            return;
        }

        p=head;
        int i=0;
        while(i<cnt)
        {
            printf("%d ",head->val);
            head=head->next;
            i++;
        }

        puts("");
        head=p;
    }

    void insert_last(int x)
    {
        node *a=(node *)malloc(sizeof(node));
        a->val=x;

        cnt++;
        if(cnt==1)
        {
            head=(node *)malloc(sizeof(node));
            head->val=x;
            tail=head;
            tail->next=head;
            return;
        }

        tail->next=a;
        tail=a;
        tail->next=head;
    }

    void insert_first(int x)
    {
        node *a=(node *)malloc(sizeof(node));
        a->val=x;

        cnt++;
        if(head==NULL && tail==NULL)
        {
            head=a;
            tail=a;
            head->next=tail;
            tail->next=head;
            return;
        }

        a->next=head;
        head=a;
        tail->next=head;

    }

    int delete_first()
    {
        if(!cnt)
        {
            puts("ERR");
            return -1;
        }

        cnt--;
        int x=head->val;
        head=head->next;
        tail->next=head;

        return x;
    }

    int delete_last()
    {
        if(!cnt)
        {
            puts("ERR");
            return -1;
        }

        cnt--;
        int x=tail->val, i=0;
        node *p=(node *)malloc(sizeof(node));
        node *prev=(node *)malloc(sizeof(node));
        p=head;

        while(i<cnt)
        {
            prev=head;
            head=head->next;
            i++;
        }

        head=p;
        prev->next=head;
        tail=prev;
        return x;
    }

    void search_first(int x)
    {
        int flag=0, i=0;
        node *p;
        p=head;

        while(i<cnt)
        {
            if(p->val==x)
            {
                flag=1;
                printf("The value is found at node %d from first\n",i+1);
            }
            p=p->next;
            i++;
        }

        if(!flag) puts("Value not found");
    }

    void search_last(int x)
    {
        int flag=0, i=0;
        node *p;
        p=head;

        while(i<cnt)
        {
            if(p->val==x)
            {
                flag=1;
                printf("The value is found at node %d from last\n",cnt-i);
            }
            p=p->next;
            i++;
        }

        if(!flag) puts("Value not found");
    }

    void kill(int k)
    {
        node *p;
        node *prev;
        p=head;

        while(1)
        {
            prev=head;
            head=head->next;
            k--;
            if(k==1) break;
        }


        cnt--;
        head=head->next;
        prev->next=head;

    }

    int top()
    {
        return head->val;
    }

};

int main()
{
    Circular_linked_list L;

    int n, k, i;
    scanf("%d %d",&n,&k);

    for(i=1; i<=n; i++) L.insert_last(i);

    while(L.cnt!=1) L.kill(k);

    printf("%d\n",L.top());
    return 0;
}

