#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    node *left;
    node *right;
};

struct BST
{
    node *root;

    BST()
    {
        root=NULL;
    }

    void insert__(node *p, int v)
    {
        if(v==p->val)
        {
            return;
        }

        if(v<p->val)
        {
            if(p->left==NULL)
            {
                (p->left)=(node *)malloc(sizeof(node));
                (p->left)->val=v;
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
                (p->right)=(node *)malloc(sizeof(node));
                (p->right)->val=v;
                (p->right)->left=NULL;
                (p->right)->right=NULL;
                return;
            }
            else insert__(p->right, v);
        }

    }

    void insert(int v)
    {
        if(root==NULL)
        {
            root=(node *)malloc(sizeof(node));
            root->val=v;
            root->left=NULL;
            root->right=NULL;
            return;
        }

        node *temp;
        temp=root;
        insert__(temp, v);
        return;
    }

    void pr1(node *temp)
    {
        if(temp==NULL) return;
        printf("%d ", temp->val);
        pr1(temp->left);
        pr1(temp->right);
    }

    void pr2(node *temp)
    {
        if(temp==NULL) return;
        pr2(temp->left);
        printf("%d ", temp->val);
        pr2(temp->right);
    }

    void pr3(node *temp)
    {
        if(temp==NULL) return;
        pr3(temp->left);
        pr3(temp->right);
        printf("%d ", temp->val);
    }

    void inOrder()
    {
        node *temp;
        temp=root;
        pr2(temp);
        puts("");
    }

    void preOrder()
    {
        node *temp;
        temp=root;
        pr1(temp);
        puts("");
    }

    void postOrder()
    {
        node *temp;
        temp=root;
        pr3(temp);
        puts("");
    }

    void search_(node *temp, int v)
    {
        if(temp==NULL)
        {
            puts("Not Found");
            return;
        }

        if(v==temp->val)
        {
            puts("Found");
            return;
        }

        if(v<temp->val) search_(temp->left, v);
        else search_(temp->right, v);
    }

    void search(int v)
    {
        node *temp;
        temp=root;
        search_(temp, v);
        puts("");
    }

    node *getMin(node *temp)
    {
        node *curr;
        curr=temp;
        while(curr->left!=NULL) curr=curr->left;
        return curr;
    }

    node *getMax(node *temp)
    {
        node *curr;
        curr=temp;
        while(curr->right!=NULL) curr=curr->right;
        return curr;
    }

    node *deleteNode(node *p, int v)
    {
        if(p==NULL) return p;

        if(v<p->val) p->left=deleteNode(p->left, v);
        else if(v>p->val) p->right=deleteNode(p->right, v);
        else
        {
            if(p->left==NULL)
            {
                node *temp=p->right;
                free(p);
                return temp;
            }
            else if(p->right==NULL)
            {
                node *temp=p->left;
                free(p);
                return temp;
            }

            node *temp=getMin(p->right);
            p->val=temp->val;
            p->right=deleteNode(p->right, temp->val);
        }

        return p;
    }

    void delete_(int val)
    {
        root=deleteNode(root, val);
    }

    int MIN()
    {
        node *t=getMin(root);
        return t->val;
    }

    int MAX()
    {
        node *t=getMax(root);
        return t->val;
    }

};

int main()
{

    BST L;
    L.insert(1);
    L.insert(5);
    L.insert(2);
    L.insert(3);

    printf("Min is: %d\n", L.MIN());
    printf("Max is: %d\n", L.MAX());


    L.search(6);

    L.preOrder();

    L.delete_(2);
    L.delete_(1);
    L.inOrder();
    L.postOrder();

    return 0;
}
