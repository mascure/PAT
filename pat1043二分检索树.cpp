//1043. Is It a Binary Search Tree (25)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#define MAXN 1005
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};
int num[MAXN];
bool checkBST(int start,int end,int& iL,int& iR)
{
    iL=start+1;
    //找左子树根节点
    if(!(iL<=end&&num[iL]<num[start]))
        iL=-1;
    //找右子树根节点
    iR=start+1;
    while(iR<=end&&num[iR]<num[start])
        iR++;
    //没有右子树
    if(iR==end+1)
    {
        iR=-1;
        return true;
    }
    int j=iR;
    //确保右子树全部大于等于根节点
    while(j<=end&&num[j]>=num[start])
        j++;
    if(j!=end+1)
        return false;
    return true;
}
bool checkMirrorBST(int start,int end,int& iL,int& iR)
{
    iL=start+1;
    //找左子树根节点
    if(!(iL<=end&&num[iL]>=num[start]))
        iL=-1;
    iR=start+1;
    //找右子树根节点
    while(iR<=end&&num[iR]>=num[start])
        iR++;
    //没有右子树
    if(iR==end+1)
    {
        iR=-1;
        return true;
    }
    int j=iR;
    //确保右子树全部小于根节点
    while(j<=end&&num[j]<num[start])
        j++;
    if(j!=end+1)
        return false;
    return true;
}
bool buildBST(Node* root,int start,int end)
{
    root->key=num[start];
    root->left=NULL;
    root->right=NULL;
    int iL,iR;
    if(checkBST(start,end,iL,iR))
    {
        if(iL!=-1)
        {
            Node* left=new Node;
            root->left=left;
            int Lend=iR-1;
            if(iR==-1)Lend=end;
            if(!buildBST(left,iL,Lend))
                return false;
        }
        if(iR!=-1)
        {
            Node* right=new Node;
            root->right=right;
            if(!buildBST(right,iR,end))
                return false;
        }
        return true;
    }
    else
        return false;
}
bool buildMirrorBST(Node* root,int start,int end)
{
    root->key=num[start];
    root->left=NULL;
    root->right=NULL;
    int iL,iR;
    if(checkMirrorBST(start,end,iL,iR))
    {
        if(iL!=-1)
        {
            Node* left=new Node;
            root->left=left;
            int Lend=iR-1;
            if(iR==-1)Lend=end;
            if(!buildMirrorBST(left,iL,Lend))
                return false;
        }
        if(iR!=-1)
        {
            Node* right=new Node;
            root->right=right;
            if(!buildMirrorBST(right,iR,end))
                return false;
        }
        return true;
    }
    else
        return false;
}
void post_visit(Node* root)
{
    if(root==NULL)return;
    if(root->left!=NULL)
        post_visit(root->left);
    if(root->right!=NULL)
        post_visit(root->right);
    printf("%d ",root->key);
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,N;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&num[i]);
        }
        Node* root=new Node;
        root->left=NULL;
        root->right=NULL;
        if(buildBST(root,0,N-1)||buildMirrorBST(root,0,N-1))
        {
            printf("YES\n");
            post_visit(root->left);
            post_visit(root->right);
            printf("%d\n",num[0]);
        }
        else
            printf("NO\n");
    }
    return 0;
}
