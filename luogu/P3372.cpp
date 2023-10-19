/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
#define int long long
#define md ((l+r)>>1)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
using namespace std;
const int MAXN=1e5+10;
int n,m,Tadd[MAXN*4],a[MAXN];
struct SegTree
{
    int v;
}seg[MAXN*4];
void PushUp(int x)
{
    seg[x].v=seg[ls(x)].v+seg[rs(x)].v;
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        seg[p].v=a[l];
        return;
    }
    build(ls(p),l,md);
    build(rs(p),md+1,r);
    PushUp(p);
}
void add(int p,int l,int r,int x)
{
    seg[p].v+=(r-l+1)*x;
    Tadd[p]+=x;
}//tag 标记
void PushDown(int p,int l,int r)
{
    if(!Tadd[p]) return;
    add(ls(p),l,md,Tadd[p]);
    add(rs(p),md+1,r,Tadd[p]);
    Tadd[p]=0;
}
void add(int p,int l,int r,int L,int R,int x)
{
    if(r<L || R<l) return;
    if(L<=l && r<=R)
    {
        add(p,l,r,x);
        return;
    }
    PushDown(p,l,r);
    add(ls(p),l,md,L,R,x);
    add(rs(p),md+1,r,L,R,x);
    PushUp(p);
}//修改
int query(int p,int l,int r,int L,int R)
{
    if(r<L || R<l) return 0;
    if(L<=l && r<=R)
    {
        return seg[p].v;
    }
    PushDown(p,l,r);
    return query(ls(p),l,md,L,R)+query(rs(p),md+1,r,L,R);
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            add(1,1,n,x,y,k);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<"\n";
        }
    }
    return 0;
}