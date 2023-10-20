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
int n,m,tot,fa[MAXN],ans;
struct node
{
    int x,y,z;
}a[MAXM];
bool cmp(node s1,node s2)
{
    return s1.z<s2.z;
}
int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int fx=find(a[i].x),fy=find(a[i].y);
        if(fx==fy) continue;
        ans+=a[i].z;
        fa[fx]=fy;
        tot++;
        if(tot>=n-1)
        {
            break;
        }
    }
    if(tot<n-1)
    {
        puts("orz");
    }
    else
    {
        cout<<ans<<"\n";
    }
    return 0;
}