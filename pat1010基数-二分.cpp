//pat1010 Radix (25)
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits>
using namespace std;
int equal(char* A, char* B){
    int i,j;
    for(i=0;i<strlen(A);i++) if(A[i]!='0') break;
    for(j=0;j<strlen(B);j++) if(B[j]!='0') break;
    int lenA = strlen(A);
    int lenB = strlen(B);
    if(lenA-i != lenB-j) return -1;
    for(int k=0;k<lenA-i;k++)
        if(A[lenA-1-k]!=B[lenB-1-k]) return false;
    if(lenA-i==1&&A[lenA-1]=='1') return 1;
    return 2;
}
long long char2ll(char* p,int radix)
{
    long long ans=0;
    int i=0;
    while(p[i]!='\0')
    {
        int r;
        if(p[i]>='0'&&p[i]<='9')
        r=p[i]-'0';
        else if(p[i]>='a'&&p[i]<='z')
        r=p[i]-'a'+10;
        ans=ans*radix+r;
        i++;
    }
    return ans;
}
int findMaxDigit(char* p)
{
    int i=0,ans=0;
    while(p[i]!='\0')
    {
        int r;
        if(p[i]>='0'&&p[i]<='9')
        r=p[i]-'0';
        else if(p[i]>='a'&&p[i]<='z')
        r=p[i]-'a'+10;
        if(r>ans)ans=r;
        i++;
    }
    return ans;
}
int compare(char* p,long long radix,long long n)
{
    long long ans=0;
    int i=0;
    while(p[i]!='\0')
    {
        int r;
        if(p[i]>='0'&&p[i]<='9')
        r=p[i]-'0';
        else if(p[i]>='a'&&p[i]<='z')
        r=p[i]-'a'+10;
        ans=ans*radix+r;
        if(ans>n)return 1;
        i++;
    }
    if(ans<n)return -1;
    else return 0;
}
long long binarySearch(char* p,long long L,long long R,long long n)
{
    long long mid;
    while(L<=R)
    {
        mid=(L+R)/2;
        int result=compare(p,mid,n);
        if(result>0)
        R=mid-1;
        else if(result<0)
        L=mid+1;
        else return mid;
    }
    return -1;
}
int main()
{
//    char a[11]="zzzzzzzzzz";
//    printf("%lld\n",char2ll(a,36));
    char left[15],right[15];
    int tag,radix1;
    long long n1;
    while(scanf("%s%s%d%d",left,right,&tag,&radix1)!=EOF)
    {
        int tmp=equal(left,right);
        if(tmp==1)
        {
            printf("2\n");
            continue;
        }
        else if(tmp==2)
        {
            printf("%d\n",radix1);
            continue;
        }
        //交换两个数
        if(tag==2)
        {
            char temp[15];
            strcpy(temp,left);
            strcpy(left,right);
            strcpy(right,temp);
        }
        n1=char2ll(left,radix1);
        long long L=findMaxDigit(right)+1;
        long long R=n1>L?n1:L;
        long long ans=binarySearch(right,L,R,n1);
        if(ans==-1)printf("Impossible\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
