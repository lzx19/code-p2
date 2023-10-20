/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
const int MAXM=5e5+10;
int n,m,s,d[MAXN];
int hed[MAXN],to[MAXM],val[MAXM],nxt[MAXM],cnt;
bitset <MAXN> vis;
queue <int> q; 
void add(int u,int v,int w)
{
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=hed[u];
    hed[u]=cnt;
}
void spfa()
{
    memset(d,0x3f,sizeof d);
    d[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=hed[u];i;i=nxt[i])
        {
            int v=to[i],w=val[i];
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
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
    spfa();
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0x3f3f3f3f) cout<<"2147483647 ";
        else cout<<d[i]<<" ";
    }
    return 0;
}