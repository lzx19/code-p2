/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=300+10;
int n,m,k[MAXN],s[MAXN],f[MAXN][MAXN];
vector <int> V[MAXN];
void dfs(int u)
{
    for(auto v:V[u])
    {
        dfs(v);
    }
    for(auto v:V[u])
    {
        for(int i=m;i;i--)
        {
            for(int j=1;j<=i;j++)
            {
                f[u][i]=max(f[u][i],f[u][j]+f[v][i-j]);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    m++;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        V[x].push_back(i);
        f[i][1]=y;
    }
    dfs(0);
    cout<<f[0][m]<<"\n";
    return 0;
}