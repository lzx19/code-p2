/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int read(){int x=0,w=1;char ch=0;while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}return x*w;}
void write(int x){static int sta[70];int top=0;do{sta[top++]=x%10,x/=10;}while(x);while(top)putchar(sta[--top]+48);}


int n,m,a[MAXN],b[MAXN],c[MAXN],q,p[MAXN],f[MAXN],s[MAXN];
void work()
{
    int inJ=0,outJ=0,ans=LLONG_MAX;
    m=read();
    for(int i=1;i<=m;i++)
    {
        p[i]=read();
        inJ+=c[p[i]];
    }
    p[m+1]=n+1;
    for(int i=m;i;i--)
    {  
        ans=min(ans,inJ+outJ+f[p[i+1]-1]);
        outJ+=s[p[i+1]-1]-s[p[i]];
        inJ-=c[p[i]];
    }
    write(min(ans,inJ+outJ+f[p[1]-1]));
    puts("");
}
signed main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=read();
    }
    f[1]=min(a[1],b[1]);
    s[1]=b[1];
    for(int i=2;i<=n;i++)
    {
        f[i]=min(f[i-1]+b[i],a[i]);
        s[i]=s[i-1]+b[i];
    }
    q=read();
    while(q--)
    {
        work();
    }
    return 0;
}