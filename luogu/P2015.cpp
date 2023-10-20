/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100+10,MAXM=200+10;
int n,q,lc[MAXN],rc[MAXN],a[MAXN],f[MAXN][MAXN];
int hed[MAXN],to[MAXM],nxt[MAXM],val[MAXM],cnt;
void add(int u,int v,int w)
{
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=hed[u];
    hed[u]=cnt;
}
void dfs1(int u,int fa)
{
    for(int j=1,i=hed[u];i;i=nxt[i])
    {
        int v=to[i],w=val[i];
        if(v==fa) continue;
        if(j==1)
        {
            lc[u]=v;
            j++;
        }
        else rc[u]=v;
        a[v]=w;
    }
    if(!lc[u]) return;
    dfs1(lc[u],u);
    dfs1(rc[u],u);
}
void dfs2(int u)
{
    if(!lc[u]) return;
    dfs2(lc[u]);
    dfs2(rc[u]);
    for(int i=1;i<=q;i++)
    {
        f[u][i]=max(a[lc[u]]+f[lc[u]][i-1],a[rc[u]]+f[rc[u]][i-1]);
        for(int j=0;j<=i-2;j++)
        {
            f[u][i]=max(a[lc[u]]+f[lc[u]][j]+a[rc[u]]+f[rc[u]][i-2-j],f[u][i]);
        }
    }
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs1(1,0);
    dfs2(1);
    cout<<f[1][q]<<"\n";
    return 0;
}