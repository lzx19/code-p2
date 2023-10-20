/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+10;
int n,d[MAXN],top=1;
int hed[MAXN],val[MAXN*2],to[MAXN*2],nxt[MAXN*2],cnt,trie[MAXN*31][2];
void add(int u,int v,int w)
{
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=hed[u];
    hed[u]=cnt;
}
void dfs(int u,int fa)
{
    for(int i=hed[u];i;i=nxt[i])
    {
        int v=to[i],w=val[i];
        if(v==fa) continue;
        d[v]=d[u]^w;
        dfs(v,u);
    }
}
void ADD(int x)
{
    int p=1;
    for(int i=30;i>=0;i--)
    {
        int y=(x>>i)&1;
        if(!trie[p][y])
        {
            trie[p][y]=++top;
        }
        p=trie[p][y];
    }
}
int query(int x)
{
    int p=1,ct=0;
    for(int i=30;i>=0;i--)
    {
        int y=(x>>i)&1;
        y^=1;
        if(trie[p][y])
        {
            p=trie[p][y];
            ct+=(1<<i);
        }
        else
        {
            p=trie[p][y^1];
        }
    }
    return ct;
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        ADD(d[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,query(d[i]));
    }
    cout<<ans<<"\n";
    return 0;
}