//1035. Password (20)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
#define MAXN 10005
using namespace std;
struct User
{
    string name,password;
    bool modifed;
}user[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,ansN,N;
    while(scanf("%d",&N)!=EOF)
    {
        char name[20],password[20];
        ansN=0;
        for(i=0;i<N;i++)
        {
            scanf("%s%s",name,password);
            user[i].name=name;
            user[i].password=password;
            user[i].modifed=false;
            int len=strlen(password);
            user[i].modifed=false;
            for(j=0;j<len;j++)
            {
                if(user[i].password[j]=='1')
                {
                    user[i].password[j]='@';
                    user[i].modifed=true;
                }
                else if(user[i].password[j]=='0')
                {
                    user[i].password[j]='%';
                    user[i].modifed=true;
                }
                else if(user[i].password[j]=='l')
                {
                    user[i].password[j]='L';
                    user[i].modifed=true;
                }
                else if(user[i].password[j]=='O')
                {
                    user[i].password[j]='o';
                    user[i].modifed=true;
                }
            }
            if(user[i].modifed)ansN++;
        }
        if(ansN==0)
        {
            if(N<=1)
            printf("There is %d account and no account is modified\n",N);
            else
            printf("There are %d accounts and no account is modified\n",N);
        }
        else
        {
            cout<<ansN<<endl;
            for(i=0;i<N;i++)
            {
                if(user[i].modifed)
                cout<<user[i].name<<" "<<user[i].password<<endl;
            }
        }
    }
    return 0;
}
