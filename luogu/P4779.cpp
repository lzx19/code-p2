/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
const int MAXM=2e5+10;
int n,m,s,d[MAXN];
bitset <MAXN> vis;
int hed[MAXN],to[MAXM],nxt[MAXM],val[MAXM],cnt;
priority_queue < pair<int,int> > q;
void add(int u,int v,int w)
{
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=hed[u];
    hed[u]=cnt;
}
void dij()
{
    memset(d,0x3f,sizeof d);
    d[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=hed[u];i;i=nxt[i])
        {
            int v=to[i],w=val[i];
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push({-d[v],v});
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dij();
    for(int i=1;i<=n;i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}