/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
int n,m,fa[MAXN];
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
    while(m--)
    {
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1)
        {  
            int fx=find(x),fy=find(y);
            fa[fx]=fy;
        }
        else
        {
            int fx=find(x),fy=find(y);
            if(fx==fy)
            {
                puts("Y");
            }
            else puts("N");
        }
    }
    return 0;
}