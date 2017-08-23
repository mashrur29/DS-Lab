#include<bits/stdc++.h>
using namespace std;

struct info
{
    string name;
    int roll, marks, rank_;

    info()
    {

    }

    info(string nm, int rl, int mrk)
    {
        name=nm;
        roll=rl;
        marks=mrk;
        rank_=0;
    }

};

struct node
{
    info in;
    node *left;
    node *right;

    node()
    {
        left=NULL;
        right=NULL;
    }
};


struct BST
{
    node *root;

    BST()
    {
        root=NULL;
    }

    void insert__(node *p, info v)
    {

        if(v.name<=p->in.name)
        {
            if(p->left==NULL)
            {
                (p->left)=new node();
                (p->left)->in=v;
                (p->left)->left=NULL;
                (p->left)->right=NULL;
                return;
            }
            else insert__(p->left, v);
        }
        else
        {
            if(p->right==NULL)
            {
                (p->right)=new node();
                (p->right)->in=v;
                (p->right)->left=NULL;
                (p->right)->right=NULL;
                return;
            }
            else insert__(p->right, v);
        }

    }

    void insert_(info v)
    {
        if(root==NULL)
        {
            root=new node();
            root->in=v;
            root->left=NULL;
            root->right=NULL;
            return;
        }

        node *temp;
        temp=root;
        insert__(temp, v);
        return;
    }


    void pr2(node *temp)
    {
        if(temp==NULL) return;
        pr2(temp->left);
        cout<<temp->in.name<<" ";
        pr2(temp->right);
    }

    void inOrder()
    {
        node *temp;
        temp=root;
        pr2(temp);
        puts("");
    }

};

struct HEAP
{
    info heap[100];
    int top;

    HEAP()
    {
        top=0;
    }

    void insert_(info val)
    {
        if(top>=90) return;
        top+=1;
        heap[top]=val;
        heapifyUp(top);
    }

    int parent(int node)
    {
        int ret=node/2;
        if(node==1) return -1;
        else return ret;
    }

    int left(int node)
    {
        int ret=2*node;
        if(ret<=top || node==0) return ret;
        else return -1;
    }

    int right(int node)
    {
        int ret=2*node+1;
        if(ret<=top || node==0) return ret;
        else return -1;
    }

    void heapifyUp(int node)
    {
        if(node==0) return;

        if(node>1 && parent(node)>=1 && heap[parent(node)].marks<heap[node].marks)
        {
            swap(heap[parent(node)], heap[node]);
            heapifyUp(parent(node));
        }

    }

    void heapifyDown(int node)
    {
        int L=left(node);
        int R=right(node);

        if(L>=1 && R>=1 && heap[L].marks<heap[R].marks)
        {
            L=R;
        }
        if(L>=1 && node>=1 && heap[node].marks<heap[L].marks)
        {
            swap(heap[L], heap[node]);
            heapifyDown(L);
        }
    }

    void delete_max()
    {
        if(top==0) return;

        heap[1]=heap[top];
        top--;
        heapifyDown(1);
    }

    info maxi()
    {
        if(top!=0)
        {
            return heap[1];
        }
    }

    bool isEmpty()
    {
        if(top<=0) return true;
        else return false;
    }

};

int main()
{
    freopen("in.txt", "r", stdin);
    BST L;
    HEAP H;

    puts("\t\t\t\t*************Menu*************");
    puts("\t\t1. Press 1 to enter student information.");
    puts("\t\t2. Press 2 to print student information in  In-order.");
    puts("\t\t3. Press 3 to delete the information of student holding first position.");
    puts("\t\t4. Press 4 to Sort the student's information");
    puts("\t\t5. Press 5 to find the rank.");
    puts("\t\t6. Press 6 to exit.\n\n");

    int tp;

    while(scanf("%d", &tp)==1)
    {
        if(tp==1)
        {
            info x;
            cin>>x.name>>x.roll>>x.marks;
            L.insert_(x);
            H.insert_(x);
        }
        else if(tp==2)
        {
            L.inOrder();
        }
        else if(tp==3)
        {
            H.delete_max();
        }
        else if(tp==4)
        {
            HEAP tmp;
            printf("Name\t\tRoll\t\tMarks\n\n");

            while(!H.isEmpty())
            {
                tmp.insert_(H.maxi());
                cout<<H.maxi().name<<"\t\t"<<H.maxi().roll<<"\t\t"<<H.maxi().marks<<endl;
                H.delete_max();
            }

            while(!tmp.isEmpty())
            {
                H.insert_(tmp.maxi());
                tmp.delete_max();
            }
        }
        else if(tp==5)
        {
            HEAP tmp;
            int prev=-1, rnk=1;

            printf("Rank\t\tName\t\tRoll\t\tMarks\n\n\n");

            while(!H.isEmpty())
            {
                info x=H.maxi();
                if(prev!=-1 && x.marks<prev) x.rank_=++rnk;
                else x.rank_=rnk;

                cout<<x.rank_<<"\t\t"<<x.name<<"\t\t"<<x.roll<<"\t\t"<<x.marks<<endl;
                prev=x.marks;
                tmp.insert_(x);
                H.delete_max();
            }

            while(!tmp.isEmpty())
            {
                H.insert_(tmp.maxi());
                tmp.delete_max();
            }

        }
        else break;

    }

    printf("\n\t\t\t\t************Thank You************\n\n");
    return 0;
}

/*

1 aba 29 50
1 abc 30 51
1 abb 31 100
2
6

*/
