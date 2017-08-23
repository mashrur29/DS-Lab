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

};

int main()
{
    int tp;
    Circular_linked_list L;

    puts("\t\t\t\t\t*********MENU**********");
    puts("\t\t\t\t1. Enter 1 to print List");
    puts("\t\t\t\t2. Enter 2 to Insert last");
    puts("\t\t\t\t3. Enter 3 to Insert first");
    puts("\t\t\t\t4. Enter 4 to Delete first");
    puts("\t\t\t\t5. Enter 5 to Delete last");
    puts("\t\t\t\t6. Enter 6 to Search an element from first");
    puts("\t\t\t\t7. Enter 7 to Search an element from last");

    while(scanf("%d",&tp)==1)
    {
        int x;

        if(tp==1) L.print();
        else if(tp==2)
        {
            scanf("%d",&x);
            L.insert_last(x);
        }
        else if(tp==3)
        {
            scanf("%d",&x);
            L.insert_first(x);
        }
        else if(tp==4) L.delete_first();
        else if(tp==5) L.delete_last();
        else if(tp==6)
        {
            scanf("%d",&x);
            L.search_first(x);
        }
        else
        {
            scanf("%d",&x);
            L.search_last(x);
        }

    }

    return 0;
}
