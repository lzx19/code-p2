/*
Author:lzx
Blog:https://blog.lzx9.com/
Email:lzx@czoier.top
QQ:2210631299
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int n,a[MAXN],b[MAXN];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1,j=1,k=n,l=n;i<=n;i++,l--)
    {
        if(i%2==1)
        {
            b[j]=1^a[l];
            j++;
        }
        else
        {
            b[k]=a[l];
            k--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}