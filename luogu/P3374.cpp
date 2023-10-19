/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,m;
int c[MAXN];
void add(int p,int x)
{
    for(;p<=n;p+=(p&-p))
    {
        c[p]+=x;
    }
}
int query(int p)
{
    int y=0;
    for(;p;p-=(p&-p))
    {
        y+=c[p];
    }
    return y;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        add(i,x);
    }
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            add(x,y);
        }
        else
        {
            cout<<query(y)-query(x-1)<<"\n";
        }
    }
    return 0;
}