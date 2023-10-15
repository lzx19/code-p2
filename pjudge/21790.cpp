/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100+10;
const int MAXM=100+10;
const int MAXQ=100+10;
int n,m,q,st[MAXN];
char op[MAXQ],mp[MAXN][MAXM],pr[MAXN][MAXM];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>op[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    for(int qq=1;qq<=q;qq++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pr[i][j]='.';
            }
        }
        if(op[qq]=='U')
        {
            for(int i=1;i<=m;i++) st[i]=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(mp[i][j]=='.') continue;
                    pr[++st[j]][j]=mp[i][j];
                }
            }
        }
        if(op[qq]=='D')
        {
            for(int i=1;i<=m;i++) st[i]=n+1;
            for(int i=n;i;i--)
            {
                for(int j=1;j<=m;j++)
                {
                    if(mp[i][j]=='.') continue;
                    pr[--st[j]][j]=mp[i][j];
                }
            }
        }
        if(op[qq]=='L')
        {
            for(int i=1;i<=n;i++) st[i]=0;
            for(int j=1;j<=m;j++)
            {
                for(int i=1;i<=n;i++)
                {
                    if(mp[i][j]=='.') continue;
                    pr[i][++st[i]]=mp[i][j];
                }
            }
        }
        if(op[qq]=='R')
        {
            for(int i=1;i<=n;i++) st[i]=m+1;
            for(int j=m;j;j--)
            {
                for(int i=1;i<=n;i++)
                {
                    if(mp[i][j]=='.') continue;
                    pr[i][--st[i]]=mp[i][j];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mp[i][j]=pr[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            putchar(mp[i][j]);
        }
        puts("");
    }
    return 0;
}