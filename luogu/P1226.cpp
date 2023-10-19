#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p;
int kasumi(int a,int b,int p)
{
    int cnt=a,ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*cnt%p;
        }
        cnt=cnt*cnt%p;
        b>>=1;
    }
    return ans;
}
signed main()
{
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<kasumi(a,b,p)<<"\n";
    return 0;
}
