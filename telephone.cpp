#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int id;
    int dep;
    Node *left;
    Node *right;
    int height;

};
struct cumulative_maximum
{
    int max_recharge;
    int user_id;

    cumulative_maximum() : max_recharge{-1}, user_id{-1}
    {}
};
int height(Node *n)
{
    if(n==NULL)
     return 0;
    return n->height;
}
Node* newNode(int id,int dep)
{
    Node *node=new Node();
    node->id=id;
    node->dep=dep;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
Node *rightRotate(Node *y)
{
    Node *x=y->left;
    Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
Node *leftRotate(Node *N)
{
    Node *y=N->right;
    Node *T2=y->left;
    y->left=N;
    N->right=T2;
    N->height = max(height(N->left),
                    height(N->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    return y;
}
int getbalance(Node *N)
{
    if(N==NULL)
    {
        return 0;
    }
    return height(N->left)-height(N->right);
}
Node* insertn(Node * node,int id,int dep)
{
    if(node==NULL)
    {
        return newNode(id,dep);
    }
    if(id<node->id)
    {
        node->left=insertn(node->left,id,dep);
    }
    else if(id>node->id)
    {
        node->right=insertn(node->right,id,dep);
    }
    else if(id==node->id){

        return node;
    }
    node->height=1+max(height(node->left),height(node->right));
    int balance=getbalance(node);

    if(balance>1 && id < node->left->id)
    {
      return rightRotate(node);
    }
    if(balance<-1 && id > node->right->id)
    {
        return leftRotate(node);
    }
    if(balance>1 && id > node->left->id)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && id < node->right->id)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
return node;
}
Node* searchn(Node* root, int id)
{
    if(root == nullptr || root -> id == id)
    {
        return root;
    }
    if(root -> id < id)
        return searchn(root -> right, id);

    return searchn(root -> left, id);
}

int main()
{
    Node *root=NULL;
    Node *temp;
    int u;
    cin>>u;
    cumulative_maximum m;
    while(1)
    {
        int x;
        cin>>x;

        if(x==1)
        {
            int id,dep;
            cin>>id>>dep;
            temp=searchn(root,id);
            if(temp==NULL)
            {
                root=insertn(root,id,dep);
                if(dep>m.max_recharge)
            {
                m.max_recharge=dep;
                m.user_id=id;
            }
            }
            else
            {
                temp->dep+=dep;
            if(temp->dep>m.max_recharge)
            {
                m.max_recharge=temp->dep;
                m.user_id=id;
            }
            }
        }
        else if(x==2)
        {

          if(m.max_recharge==-1)
          {
              cout<<"No data available";
          }
          else
          cout<<m.user_id<<endl;
        }
        else
            break;

    }

    return 0;
}
