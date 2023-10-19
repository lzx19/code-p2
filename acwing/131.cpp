#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100000+10;
int n,ans,h[MAXN],st[MAXN],w[MAXN],top;
void work()
{
    ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    h[n+1]=0;
    top=0;
    for(int i=1;i<=n+1;i++)
    {
        if(h[i]>st[top])
        {
            st[++top]=h[i];
            w[top]=1;
        }
        else
        {
            int W=0;
            while(h[i]<st[top])
            {
                W+=w[top];
                ans=max(ans,W*st[top]);
                top--;
            }
            st[++top]=h[i];
            w[top]=W+1;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    while(1)
    {
        cin>>n;
        if(n==0) return 0;
        work();
    }
    return 0;
}
