#include<bits/stdc++.h>
using namespace std;
bool vis[60][60];
char a[60][60];
int cnt;
int m,n;
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
bool vaild(int ci,int cj)
{
    return ci>=0&&ci<n&&cj>=0&&cj<m&&a[ci][cj]!='#';
}
void dfs(int si,int sj)
{
    vis[si][sj]=true;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(vaild(ci,cj)&&!vis[ci][cj])
        {
            dfs(ci,cj);
        }
    }
}
int main()
{
    int t;
    cin>>t;
     int cs = 1;
    while(t--)
    {
    cin>>m>>n;
    int si,sj;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j <m; j++)
        {
           cin>>a[i][j];
           if(a[i][j]=='@')
           {
            si=i;
            sj=j;
           }
        }      
    }
        cnt=0;
        memset(vis, false, sizeof(vis));
        dfs(si, sj);
        cout << "Case " << cs++ << ": " << cnt << endl;
    }
    return 0;
}