//http://pat.zju.edu.cn/contests/pat-a-practise/1066
/*
平衡二叉树的插入算法,21分，一个case段错误
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
#define MAXN 40005
using namespace std;

struct Node
{
    int key;
    int LH,RH;
    Node *LChild,*RChild,*parent;
};

Node* insert(Node* root,int key)
{
    //插入右子树
    if(key>root->key)
    {
        root->RH++;
        if(root->RChild==NULL)
        {
            Node* p=root->RChild=new Node;
            p->key=key;
            p->LH=0;
            p->RH=0;
            p->LChild=NULL;
            p->RChild=NULL;
            p->parent=root;
            return p;
        }
        else
        {
            return insert(root->RChild,key);
        }
    }
    //插入左子树
    else
    {
        root->LH++;
        if(root->LChild==NULL)
        {
            Node* p=root->LChild=new Node;
            p->key=key;
            p->LH=0;
            p->RH=0;
            p->LChild=NULL;
            p->RChild=NULL;
            p->parent=root;
            return p;
        }
        else
        {
            return insert(root->LChild,key);
        }
    }
}

Node* leftRotate(Node* p,Node* root)
{
    Node* parent=NULL;
    if(p==root)
    {
        root=p->LChild;
        root->parent=NULL;
    }
    else
    parent=p->parent;
    Node *L=p->LChild,*LR=L->RChild;
    //更新p的左孩子为LR
    p->LChild=LR;
    if(LR!=NULL)LR->parent=p;
    if(LR==NULL)
    p->LH=0;
    else
    p->LH=max(LR->LH,LR->RH)+1;
    //更新L的右孩子为p：
    p->parent=L;
    L->RChild=p;
    L->RH=max(p->LH,p->RH)+1;
    //更新p原来的父节点
    if(parent!=NULL)
    {
        if(parent->key>L->key)
        {
            parent->LChild=L;
            L->parent=parent;
        }
        else
        {
            parent->RChild=L;
            L->parent=parent;
        }
    }
    return root;
}

Node* rightRotate(Node* p,Node* root)
{
    Node* parent=NULL;
    if(p==root)
    {
        root=p->RChild;
        root->parent=NULL;
    }
    else
    parent=p->parent;
    Node *R=p->RChild,*RL=R->LChild;
    //更新p的右孩子为RL
    p->RChild=RL;
    if(RL!=NULL)RL->parent=p;
    if(RL==NULL)p->RH=0;
    else
    p->RH=max(RL->LH,RL->RH)+1;
    //更新R的左孩子为p
    R->LChild=p;
    p->parent=R;
    R->LH=max(p->LH,p->RH)+1;
    //更新原来p的父节点
    if(parent!=NULL)
    {
        if(parent->key>R->key)
        {parent->LChild=R;R->parent=parent;}
        else
        {parent->RChild=R;R->parent=parent;}
    }
    return root;
}

void updateH(Node* root)
{
    Node *p=root->parent,*last=root;
    while(p!=NULL)
    {
        if(p->key>last->key)
        p->LH--;
        else
        p->RH--;
        last=p;
        p=p->parent;
    }
}

Node* LL(Node* p,Node* root)
{
    root=leftRotate(p,root);
    updateH(p->parent);
    return root;
}
Node* RR(Node* p,Node* root)
{
    root=rightRotate(p,root);
    updateH(p->parent);
    return root;
}
Node* LR(Node* p,Node* root)
{
    root=rightRotate(p->LChild,root);
    root=leftRotate(p,root);
    updateH(p->parent);
    return root;
}
Node* RL(Node* p,Node* root)
{
    root=leftRotate(p->RChild,root);
    root=rightRotate(p,root);
    updateH(p->parent);
    return root;
}

Node* insert_balance(Node* root,int key)
{
    if(root==NULL)
    {
        root=new Node;
        root->key=key;
        root->LH=0;
        root->RH=0;
        root->LChild=NULL;
        root->RChild=NULL;
        root->parent=NULL;
        return root;
    }
    Node* leaf=insert(root,key);
    Node* p=leaf;
    while(p!=NULL&&p->LH-p->RH>-2&&p->LH-p->RH<2)
    {
        p=p->parent;
    }
    if(p==NULL)
    return root;
    //左孩子
    if(p->LH-p->RH==2)
    {
        //LL型
        if(leaf->key<p->LChild->key)
        {
            return root=LL(p,root);
        }
        //LR型
        else
        {
            return root=LR(p,root);
        }
    }
    //右孩子
    else
    {
        //RR型
        if(leaf->key>p->RChild->key)
        {
            return root=RR(p,root);
        }
        //RL型
        else
        {
            return root=RL(p,root);
        }
    }
    return root;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,N,key;
    while(scanf("%d",&N)!=EOF)
    {
        Node* root=NULL;
        for(i=0;i<N;i++)
        {
            scanf("%d",&key);
            root=insert_balance(root,key);
        }
        printf("%d\n",root->key);
    }
    return 0;
}
