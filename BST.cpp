#include<bits/stdc++.h>
using namespace std;

struct node
{
    string val;
    node *left;
    node *right;
}*root;

class BST
{
public:
    void insert(node *, string);
    int search(string);
    void inOrder(node *);
    void preOrder(node *);

    BST()
    {
        root=NULL;
    }
};

int main()
{
    BST L;
    L.insert(root, "3");
    L.insert(root, "1");
    L.insert(root, "4");

    L.inOrder(root);
    puts("");

    L.preOrder(root);
    puts("");

    cout<<L.search("3")<<endl;
    cout<<L.search("ab")<<endl;
}

void BST::insert(node *r, string v)
{
    if(root==NULL)
    {
        root=new node;
        root->val=v;
        root->left=NULL;
        root->right=NULL;
        return;
    }

    if(r->val==v) return;

    if(v<r->val)
    {
        if(r->left!=NULL) insert(r->left, v);
        else
        {
            r->left=new node;
            (r->left)->val=v;
            (r->left)->left=NULL;
            (r->left)->right=NULL;
        }
    }
    else
    {
        if(r->right!=NULL) insert(r->right, v);
        else
        {
            r->right=new node;
            (r->right)->val=v;
            (r->right)->left=NULL;
            (r->right)->right=NULL;
        }
    }
}


int BST::search(string v)
{
    node *t=root;

    while(1)
    {
        if(root==NULL) break;
        if(root->val==v)
        {
            root=t;
            return 1;
        }
        if(v<root->val) root=root->left;
        else root=root->right;
    }

    root=t;
    return 0;
}

void BST::inOrder(node *r) {
  if(r==NULL || root==NULL) return;
  inOrder(r->left);
  cout<<r->val<<" ";
  inOrder(r->right);
}

void BST::preOrder(node *r) {
  if(r==NULL || root==NULL) return;
  cout<<r->val<<" ";
  preOrder(r->left);
  preOrder(r->right);
}
