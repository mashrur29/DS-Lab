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

    int Top_of()
    {
      return head->val;
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

struct Queue
{
    DLL L;
    int c=0;

    void push(int x)
    {
        c++;
        L.insert_last(x);
    }

    int top()
    {
        return L.Top_of();
    }

    int pop()
    {
        if(!c)
        {
            puts("ERR");
            return -1;
        }

        c--;
        int t=L.Top_of();
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

int main(){
  int tp,temp;
  Queue q;

    puts("\t\t\t\t\t*********MENU**********");
    puts("\t\t\t\t1. Enter 1 to push.");
    puts("\t\t\t\t2. Enter 2 to pop.");
    puts("\t\t\t\t3. Enter 3 to print top.");
    puts("\t\t\t\t4. Enter 4 to check whether the queue is empty or not.");
    puts("\t\t\t\t5. Enter 5 to print queue.");

    printf("\n\n");

    while(scanf("%d",&tp)==1)
    {

        if(tp==1)
        {
            scanf("%d",&temp);
            q.push(temp);
        }
        else if(tp==2)
        {
            printf("%d\n",q.pop());
        }
        else if(tp==3) printf("%d\n",q.top());
        else if(tp==4)
        {
            if(q.isEmpty()) puts("Empty");
            else puts("Not Empty");
        }
        else q.print_();
    }

}
