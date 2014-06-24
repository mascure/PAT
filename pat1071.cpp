//pat1071 Speech Patterns
#include<stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;
bool is_alpha_num(char c)
{
    if((c>='a'&&c<='z')||(c>='0'&&c<='9'))
    return true;
    else
    return false;
}

int main()
{
    map<string,int> word;
    map<string,int>::iterator iter,ans;
    string in;
    getline(cin,in);
    int i=0,end=in.length(),start=-1,len=0;
    for(i=0;i<end;i++)
    {
        if(in[i]>='A'&&in[i]<='Z')
        in[i]+=('a'-'A');
    }
    //cout<<in<<endl;
    i=0;
    while(i<end)
    {
        if(is_alpha_num(in[i]))
        {
            //开始拼接一个单词
            start=i,len=1;
            i++;
            while(i<end&&is_alpha_num(in[i]))
            {
                i++;
                len++;
            }
            word[in.substr(start,len)]++;
            i--;
        }
        i++;
    }
    int max=0;
    for(iter=word.begin();iter!=word.end();iter++)
    {
        if(iter->second>max)
        {
            ans=iter;
            max=iter->second;
        }
    }
    cout<<ans->first<<" "<<ans->second<<endl;
    return 0;
}
