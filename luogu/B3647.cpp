/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100+10;
int n,m,f[MAXN][MAXN];
int main()
{
    memset(f,0x3f,sizeof f);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        f[u][v]=min(f[u][v],w);
        f[v][u]=min(f[v][u],w);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<f[i][j]<<" ";
        }
        puts("");
    }
    return 0;
}