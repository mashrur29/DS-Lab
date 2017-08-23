#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    node *next;
    node *prev;
};

struct DLL
{
    node *head=NULL, *tail=NULL;

    DLL()
    {
        head=(node *)malloc(sizeof(node));
        tail=(node *)malloc(sizeof(node));
        head->val=1;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }

    void print_()
    {
        if(head==NULL)
        {
            puts("EMPTY");
            return;
        }
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
        a->prev=tail;
        tail->next=a;
        tail=tail->next;
    }

    void insert_first(int x)
    {
        node *a=(node *)malloc(sizeof(node));
        a->val=x;
        a->next=head;
        a->prev=NULL;
        head->prev=a;
        head=head->prev;
    }

    void delete_first()
    {
        head=head->next;
    }

    void delete_last()
    {
        tail=tail->prev;
        tail->next=NULL;
    }

    void search_first(int n)
    {
        int flag=0,c=1;

        node *p=(node *)malloc(sizeof(node));
        p=head;
        while(head->next!=NULL)
        {
            if(head->val==n)
            {
                flag=1;
                break;
            }
            c++;
            head=head->next;
        }

        if(head->val==n && !flag) flag=1;
        head=p;

        if(flag) printf("Element found in node %d from first\n",c);
        else printf("Not found\n");
    }

    void search_last(int n)
    {
        int flag=0,c=1;

        node *p=(node *)malloc(sizeof(node));
        p=tail;
        while(tail->prev!=NULL)
        {
            if(tail->val==n)
            {
                flag=1;
                break;
            }
            tail=tail->prev;
            c++;
        }

        if(tail->val==n && !flag) flag=1;
        tail=p;

        if(flag) printf("Element found in node %d from last\n",c);
        else printf("Not found\n");
    }

    node* search_(int x)
    {
        int f=0;
        node *p;
        p=head;

        while(p!=NULL)
        {
            if(p->val==x)
            {
                break;
            }
            p=p->next;
        }

        return p;
    }

    void insert_(node *temp, int x)
    {
        node *p;
        node *t;
        node *tmp=(node *)malloc(sizeof(node));
        p=search_(x);
        tmp->val=temp->val;

        if(p==NULL)
        {
            puts("Not Found");
            return ;
        }

        t=p->prev;
        tmp->prev=p->prev;
        tmp->next=p;
        if(t!=NULL) t->next=tmp;
        else head=tmp;

        t=p->next;
        temp->next=p->next;
        if(t!=NULL) t->prev=temp;
        p->prev=tmp;
        p->next=temp;
    }

};

int main()
{
    DLL L;
    int x,k;
    printf("\n");
    puts("\t\t\t\tEnter node value and the value of the new node to insert.\n\n");

    while(scanf("%d %d",&k,&x)==2)
    {
        node *t=(node *)malloc(sizeof(node));
        t->val=x;
        L.insert_(t,k);
        L.print_();
    }

    return 0;
}

