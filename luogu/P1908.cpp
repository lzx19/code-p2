/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=5e5+10;
int n,a[MAXN],b[MAXN],c[MAXN],m;
LL ans;
void add(int p,int x)
{
    for(;p<=m;p+=(p&-p))
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
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    m=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+1+m,a[i])-b;
        add(a[i],1);
        ans+=query(m)-query(a[i])+0LL;
    }
    cout<<ans<<"\n";
    return 0;
}