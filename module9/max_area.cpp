#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[55][55];
    int ans,n,m;
    vector<pair<int,int>>d={{1,0},{0,-1},{-1,0},{0,1}};
    bool vaild(int ci,int cj,vector<vector<int>>& grid)
    {
        return ci>=0&&cj<n&&cj>=0&&cj<m&&grid[ci][cj]!=0;
    }
    void dfs(int si,int sj,vector<vector<int>>& grid)
    {
        vis[si][sj]=true;
        ans++;
        for(int i=0;i<4;i++)
        {
            int ci=si+d[i].first;
            int cj=si+d[i].second;
            if(vaild(ci,cj,grid)&&!vis[ci][cj]&&grid[ci][cj]==1)
            {
                dfs(ci,cj,grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        memset(vis,false,sizeof(vis));
        int mx=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1)
                {
                    ans=0;
                    dfs(i,j,grid);
                    mx=max(mx,ans);
                }
            }
        }
        return mx;
        
    }
};