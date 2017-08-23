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
    node *head=NULL,*tail=NULL;

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
        if(head==NULL && tail==NULL)
        {
            a->prev=NULL;
            head=a;
            tail=a;
            return;
        }

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

};

int main()
{
    int tp,temp;
    DLL L;

    puts("\t\t\t\t\t*********MENU**********");
    puts("\t\t\t\t1. Enter 1 to print List");
    puts("\t\t\t\t2. Enter 2 to Insert last");
    puts("\t\t\t\t3. Enter 3 to Insert first");
    puts("\t\t\t\t4. Enter 4 to Delete first");
    puts("\t\t\t\t5. Enter 5 to Delete last");
    puts("\t\t\t\t6. Enter 6 to Search an element from first");
    puts("\t\t\t\t7. Enter 7 to Search an element from last");

    printf("\n\n");

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
        else if(tp==5) L.delete_last();
        else if(tp==6)
        {
            scanf("%d",&temp);
            L.search_first(temp);
        }
        else
        {
            scanf("%d",&temp);
            L.search_last(temp);
        }

    }

    return 0;
}
