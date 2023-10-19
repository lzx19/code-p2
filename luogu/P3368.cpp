/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000+10;
int n,m,a[MAXN],c[MAXN];
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
        cin>>a[i];
        add(i,a[i]-a[i-1]);
    }
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }
        else
        {
            int x;
            cin>>x;
            cout<<query(x)<<"\n";
        }
    }
    return 0;
}