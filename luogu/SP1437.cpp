/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
const int MAXM=2e4+10;
int n,f1[MAXN],f2[MAXN],d;
int cnt,hed[MAXN],to[MAXM],val[MAXM],nxt[MAXM];
void add(int u,int v,int w)
{
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=hed[u];
    hed[u]=cnt;
}
void dfs(int u,int fa)
{
    f1[u]=f2[u]=0;
    for(int i=hed[u];i;i=nxt[i])
    {
        int v=to[i],w=val[i];
        if(v==fa) continue;
        dfs(v,u);
        int dd=f1[v]+w;
        if(dd>f1[u])
        {
            f2[u]=f1[u];
            f1[u]=dd;
        }
        else if(dd>f2[u])
        {
            f2[u]=dd;
        }
    }
    d=max(d,f1[u]+f2[u]);
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v,1);
        add(v,u,1);
    }
    dfs(1,0);
    cout<<d<<"\n";
    return 0;
}