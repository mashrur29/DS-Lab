#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    node *next;

    node()
    {
        val = 0;
        next=NULL;
    }

    node(int v)
    {
        val = v;
        next = NULL;
    }

};

struct Linked_list
{
    node *head;
    int sz;

    Linked_list()
    {
        head = NULL;
        sz = 0;
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

    void insert_(int x)
    {
        sz++;
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

    void insert_before(int k, int x)
    {
        sz++;
        node *a=head;
        node *prev;
        int cnt = 1;

        if(k==1)
        {
            node *t = new node(x);
            t->next = head;
            head = t;
            return;
        }

        while(a!=NULL)
        {
            if(cnt==k)
            {
                node *t = new node(x);
                prev->next = t;
                t->next = a;
            }

            prev = a;
            a = a->next;
            cnt++;
        }
    }

    node *copy_()
    {
        node *t = head;
        node *p = new node();
        if(head==NULL) return NULL;
        p->val = head->val;
        t = t->next;
        node *t1 = p;

        while(t!=NULL)
        {
            node *x = new node(t->val);
            t1->next = x;
            t = t->next;
            t1 = t1->next;
        }

        return p;
    }

    void delete_(int k)
    {
        if(sz) sz--;
        node *a = head;
        node *prev = head;
        int cnt = 1;

        if(k==1)
        {
            head = head->next;
            return;
        }

        while(a!=NULL)
        {
            a = a->next;
            if(cnt==k-1)
            {
                prev->next = a->next;
            }

            prev = a;
            cnt++;
        }
    }

    node *find_(int k)
    {
        node *p = head;
        int cnt = 1;
        while(p!=NULL)
        {
            if(cnt==k) return p;
            p = p->next;
            cnt++;
        }
        return NULL;
    }

    void reverse_()
    {
        int lim = sz/2;
        int cnt = 1;

        while(cnt<=lim)
        {
            node *a = find_(cnt);
            node *b = find_(lim);
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
            cnt++;
            lim--;
        }
    }

};

int main()
{
    Linked_list L;
    int tp, x;

    puts("\n\n\t ************* Menu **************\n\n");
    puts("\t  1. Press 1 to insert.");
    puts("\t  2. Press 2 to delete.");
    puts("\t  3. Press 3 to copy.");
    puts("\t  4. Press 4 to reverse.");
    puts("\t  5. Press 5 to print.\n\n");

    while(scanf("%d", &tp)==1)
    {
        if(tp==1)
        {
            scanf("%d", &x);
            L.insert_(x);
        }
        else if(tp==2)
        {
            scanf("%d", &x);
            L.delete_(x);
        }
        else if(tp==3)
        {
            Linked_list L1;
            L1.head = L.copy_();
            L1.print_();
            puts("");
        }
        else if(tp==4)
        {
            L.reverse_();
            L.print_();
        }
        else L.print_();
    }

    return 0;
}
