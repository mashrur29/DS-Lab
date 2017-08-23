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

int main()
{
    int tp,temp;
    Linked_list L;

    while(scanf("%d",&tp)==1 && tp)
    {

        if(tp==1) L.print_();
        else if(tp==2)
        {
            scanf("%d",&temp);
            L.insert_last(temp);
        }
        else if(tp==3)
        {
            scanf("%d",&temp);
            L.insert_first(temp);
        }
        else if(tp==4) L.delete_first();
        else L.delete_last();

    }

    return 0;
}
