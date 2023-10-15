/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=7+10;
int n,cnt,t;
struct node
{
    int a,b,c;
}a[MAXN];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].b;
        a[i].c=a[i].b*100/a[i].a;
        cnt+=a[i].c;
    }
    cin>>t;
    if(cnt>=t)
    {
        puts("Already Au.");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int pr=(t-cnt+100/a[i].a-1)/(100/a[i].a);
        if(pr+a[i].b>a[i].a) puts("NaN");
        else cout<<pr<<"\n";
    }
    return 0;
}