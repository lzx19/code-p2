/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
#define md ((l+r)>>1)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
using namespace std;
const int MAXN=1e5+10;
int n,m;
double a[MAXN];
struct node
{
    double s1,s2;
}seg[MAXN*4];
double tag[MAXN*4];
void PushUp(int p)
{
    seg[p].s1=seg[ls(p)].s1+seg[rs(p)].s1;
    seg[p].s2=seg[ls(p)].s2+seg[rs(p)].s2;
}
void add(int p,int l,int r,double x)
{
    tag[p]+=x;
    seg[p].s2+=2*seg[p].s1*x+(r-l+1)*x*x;
    seg[p].s1+=(r-l+1)*x;
}
void PushDown(int p,int l,int r)
{
    if(!tag[p]) return;
    add(ls(p),l,md,tag[p]);
    add(rs(p),md+1,r,tag[p]);
    tag[p]=0;
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        seg[p].s1=a[l];
        seg[p].s2=a[l]*a[l];
        return;
    }
    build(ls(p),l,md);
    build(rs(p),md+1,r);
    PushUp(p);
}
void add(int p,int l,int r,int L,int R,double k)
{
    if(R<l || r<L) return;
    if(L<=l && r<=R)
    {
        add(p,l,r,k);
        return;
    }
    PushDown(p,l,r);
    add(ls(p),l,md,L,R,k);
    add(rs(p),md+1,r,L,R,k);
    PushUp(p);
}
double query1(int p,int l,int r,int L,int R)
{
    if(R<l || r<L) return 0;
    if(L<=l && r<=R)
    {
        return seg[p].s1;
    }
    PushDown(p,l,r);
    return query1(ls(p),l,md,L,R)+query1(rs(p),md+1,r,L,R);
}
double query2(int p,int l,int r,int L,int R)
{
    if(R<l || r<L) return 0;
    if(L<=l && r<=R)
    {
        return seg[p].s2;
    }
    PushDown(p,l,r);
    return query2(ls(p),l,md,L,R)+query2(rs(p),md+1,r,L,R);
}
int main()
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
            int x,y;
            double k;
            cin>>x>>y>>k;
            add(1,1,n,x,y,k);
        }
        else if(op==2)
        {
            int x,y;
            cin>>x>>y;
            printf("%.4f\n",query1(1,1,n,x,y)/(y-x+1));
        }
        else
        {
            int x,y;
            cin>>x>>y;
            double cnt=query1(1,1,n,x,y);
            printf("%.4f\n",(query2(1,1,n,x,y)-cnt*cnt/(y-x+1)) / (y-x+1));
            //q2-2Cc+Cc=q2-Cc
        }
    }
    return 0;
}