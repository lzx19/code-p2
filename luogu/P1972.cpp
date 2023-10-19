/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,m,a[MAXN],c[MAXN],lst[MAXN],la[MAXN];
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
struct node
{
    int l,r,id,ans;
}q[MAXN];
bool cmp1(node s1,node s2)
{
    return s1.r<s2.r;
}
bool cmp2(node s1,node s2)
{
    return s1.id<s2.id;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        la[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp1);
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(la[i])
        {
            add(la[i],-1);
        }
        add(i,1);
        while(q[cnt].r==i)
        {
            q[cnt].ans=query(q[cnt].r)-query(q[cnt].l-1);
            cnt++;
        }
        if(cnt>m) break;
    }
    sort(q+1,q+1+m,cmp2);
    for(int i=1;i<=m;i++)
    {
        cout<<q[i].ans<<"\n";
    }
    return 0;
}