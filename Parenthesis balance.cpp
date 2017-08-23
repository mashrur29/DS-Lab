#include<stdio.h>
#include<stdlib.h>

struct node
{
    char val;
    node *next;
};

struct Linked_list
{
    node *head=NULL;


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
            printf("%c ",head->val);
            head=head->next;
        }
        printf("%c\n",head->val);
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

    void insert_first(char x)
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

struct Stack
{
    Linked_list L;
    int c=0;

    void push(char x)
    {
        c++;
        L.insert_first(x);
    }

    char pop()
    {

        if(c==0)
        {
            printf("ERR\n");
            return -1;
        }

        c--;
        char t=L.Top_of_list();
        L.delete_first();
        return t;
    }

    char Front()
    {
        return L.Top_of_list();
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

int main()
{
    char a[100];
    scanf("%s",a);
    Stack st;
    bool f=true;

    for(int i=0; a[i]; i++)
    {

        if(a[i]=='(' || a[i]=='{' || a[i]=='[') st.push(a[i]);
        else
        {

            if(st.isEmpty())
            {
                f=false;
                break;
            }
            char temp=st.Front();

            if(temp=='(' && a[i]==')' || temp=='{' && a[i]=='}' || temp=='[' && a[i]==']') st.pop();
            else
            {
                f=false;
                break;
            }
        }

    }

    if(!st.isEmpty()) f=false;

    if(f) puts("YES");
    else puts("NO");

    return 0;
}

// (){()}()
