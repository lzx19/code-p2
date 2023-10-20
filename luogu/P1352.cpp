/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=6e3+10;
int n,r[MAXN],fa[MAXN],f[MAXN][2];
vector <int> V[MAXN];
void dfs(int u)
{
    for(auto v:V[u])
    {
        dfs(v);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
    f[u][1]+=r[u];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    for(int i=1;i<n;i++)
    {
        int l,k;
        cin>>l>>k;
        fa[l]=k;
        V[k].push_back(l);
    }
    int rt;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]) continue;
        rt=i;
        break;
    }
    dfs(rt);
    cout<<max(f[rt][0],f[rt][1])<<"\n";
    return 0;
}