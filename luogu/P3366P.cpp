/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000+10;
const int MAXM=2e5+10;
int n,m,d[MAXN],ans,tot;
bitset <MAXN> vis;
int hed[MAXN],to[MAXM*2],val[MAXM*2],nxt[MAXM*2],cnt;
priority_queue < pair <int,int> > q;
void add(int u,int v,int w)
{
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=hed[u];
    hed[u]=cnt;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    memset(d,0x3f,sizeof d);
    d[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ans+=d[u];
        tot++;
        for(int i=hed[u];i;i=nxt[i])
        {
            int v=to[i],w=val[i];
            if(d[v]>w)
            {
                d[v]=w;
                q.push({-d[v],v});
            }
        }
    }
    if(tot<n-1) puts("orz");
    else cout<<ans<<"\n";
    return 0;
}