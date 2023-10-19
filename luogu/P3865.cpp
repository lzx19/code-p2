#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int MAXN=1e5+10;
int n,m,a[MAXN],f[MAXN],lg2[MAXN],st[30][MAXN];
void init()
{
    for(int i=2;i<=n;i++)
    {
        lg2[i]=lg2[i>>1]+1;
    }
    for(int i=1;(1<<i)<=n;i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
int query(int l,int r)
{
    int k=lg2[r-l+1];
    return max(st[k][l],st[k][r-(1<<k)+1]);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        st[0][i]=a[i];
    }
    init();
    while(m--)
    {
        int l,r;
        l=read();r=read();
        cout<<query(l,r)<<"\n";
    }
    return 0;
}
