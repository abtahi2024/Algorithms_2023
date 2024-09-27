#include<bits/stdc++.h>
using namespace std;
void convert(int n,vector<pair<int,int>>adj[])
{
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=-1;
            if(i==j)
            m[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(pair<int,int>c:adj[i])
        {
            int cN=c.first;
            int co=c.second;
            m[i][cN]=co;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>v[n];
    while (e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
    }
    convert(n,v);
    

    return 0;
}