/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
#define int long long
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
#define md ((l+r)>>1)
using namespace std;
const int MAXN=1e5+10;
const int MAXNN=4e5+10;
int n,q,MOD,a[MAXN],Tadd[MAXNN],Tmul[MAXNN];
struct node
{
    int v;
}seg[MAXNN];
void PushUp(int p)
{
    seg[p].v=(seg[lc(p)].v+seg[rc(p)].v)%MOD;
}
void build(int p,int l,int r)
{
    Tmul[p]=1;
    if(l==r)
    {  
        seg[p].v=a[l];
        return;
    }
    build(lc(p),l,md);
    build(rc(p),md+1,r);
    PushUp(p);
}
void add(int p,int l,int r,int k)
{
    Tadd[p]=(Tadd[p]+k)%MOD;
    seg[p].v=(seg[p].v+(r-l+1)*k%MOD)%MOD;
}
void mul(int p,int l,int r,int k)
{
    Tadd[p]=Tadd[p]*k%MOD;
    Tmul[p]=Tmul[p]*k%MOD;
    seg[p].v=seg[p].v*k%MOD;
}
void PushDown(int p,int l,int r)
{
    if(Tmul[p]==1 && Tadd[p]==0) return;
    mul(lc(p),l,md,Tmul[p]);
    mul(rc(p),md+1,r,Tmul[p]);
    Tmul[p]=1;

    add(lc(p),l,md,Tadd[p]);
    add(rc(p),md+1,r,Tadd[p]);
    Tadd[p]=0;
}
void add(int p,int l,int r,int L,int R,int k)
{
    if(R<l || r<L) return;
    if(L<=l && r<=R)
    {
        add(p,l,r,k);
        return;
    }
    PushDown(p,l,r);
    add(lc(p),l,md,L,R,k);
    add(rc(p),md+1,r,L,R,k);
    PushUp(p);
}
void mul(int p,int l,int r,int L,int R,int k)
{
    if(R<l || r<L) return;
    if(L<=l && r<=R)
    {
        mul(p,l,r,k);
        return;
    }
    PushDown(p,l,r);
    mul(lc(p),l,md,L,R,k);
    mul(rc(p),md+1,r,L,R,k);
    PushUp(p);
}
int query(int p,int l,int r,int L,int R)
{
    if(R<l || r<L) return 0;
    if(L<=l && r<=R)
    {
        return seg[p].v;
    }
    PushDown(p,l,r);
    return (query(lc(p),l,md,L,R)+query(rc(p),md+1,r,L,R))%MOD;
}
signed main()
{
    cin>>n>>q>>MOD;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            mul(1,1,n,x,y,k);
        }
        else if(op==2)
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