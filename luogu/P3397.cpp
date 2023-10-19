#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+10;
int n,m,s[MAXN][MAXN];
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        s[x1][y1]++;
        s[x2+1][y1]--;
        s[x1][y2+1]--;
        s[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            cout<<s[i][j]<<" ";
        }
        puts("");
    }
    return 0;
}
