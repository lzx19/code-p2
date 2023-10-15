/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
int n,px,py;
int v[50][50];
string str;
vector <pair<int,int>> ans;
int main()
{
    cin>>n;
    cin>>str;
    for(int i=0;i<(1<<n);i++)
    {
        px=21;py=21;
        bool ff=1;
        memset(v,0,sizeof v);
        v[px][py]=2;
        for(int j=0;j<n;j++)
        {
            bool f=(i>>j)&1;
            if(f)
            { 
                int pyy=py,pxx=px;
                if(str[j]=='L')
                {
                    pyy--;
                }
                if(str[j]=='R')
                {
                    pyy++;
                }
                if(str[j]=='D')
                {
                    pxx--;
                }
                if(str[j]=='U')
                {
                    pxx++;
                }
                if(v[pxx][pyy]==2) goto sxy;
                else v[pxx][pyy]=1;
            }
            else
            {
                if(str[j]=='L')
                {
                    py--;
                }
                if(str[j]=='R')
                {
                    py++;
                }
                if(str[j]=='D')
                {
                    px--;
                }
                if(str[j]=='U')
                {
                    px++;
                }
                if(v[px][py]==1)
                {
                    goto sxy;
                }
                v[px][py]=2;
            }
        }
        if(ff)
        {
            ans.push_back({py,px});
        }
        sxy:;
    }
    
    sort(ans.begin(),ans.end());
    int S=ans.size();
    int lx=114514,ly=114514;
    for(auto v:ans)
    {
        int xx=v.first,yy=v.second;
        if(xx!=lx || yy!=ly) 1;
        else S--;
        lx=xx;ly=yy;
    }
    cout<<S<<"\n";
    lx=114514,ly=114514;
    for(auto v:ans)
    {
        int xx=v.first,yy=v.second;
        if(xx!=lx || yy!=ly) cout<<xx-21<<" "<<yy-21<<"\n";
        lx=xx;ly=yy;
    }
    return 0;
}