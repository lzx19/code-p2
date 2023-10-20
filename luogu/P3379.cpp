/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000+10;
int n,m,s,fa[MAXN][20],d[MAXN];
vector <int> V[MAXN];
void dfs(int u,int die)
{
    for(auto v:V[u])
    {
        if(v==die) continue;
        d[v]=d[u]+1;
        fa[v][0]=u;
        dfs(v,u);
    }
}
void init()
{
    d[s]=1;
    dfs(s,0);
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}
int query(int x,int y)
{
    if(d[x]<d[y]) swap(x,y);
    for(int i=19;i>=0;i--)
    {
        if(d[fa[x][i]]>=d[y])
        {
            x=fa[x][i];
        }
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--)
    {
        if(fa[x][i]==fa[y][i]) continue;
        x=fa[x][i];
        y=fa[y][i];
    }
    return fa[x][0];
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    init();
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<"\n";
    }
    return 0;
}