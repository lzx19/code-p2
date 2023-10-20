/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,m,a[MAXN];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int x;
        cin>>x;
        int L=1,R=n;
        while(L<R)
        {
            int mid=(L+R)>>1;
            if(a[mid]>=x) R=mid;
            else L=mid+1;
        }
        if(a[L]==x)
        {
            cout<<L<<" ";
        }
        else cout<<"-1 ";
    }
    return 0;
}