#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool vis[200005];
vector <int>v[200005];
    void dfs(int s)
    {
        vis[s]=true;
        for(int child:v[s])
        {
            if(!vis[child])
            {
                dfs(child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        memset(vis,false,sizeof(vis));
        for(int i=0;i<e.size();i++)
        {
            int a=e[i][0];
            int b=e[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(s);
        return vis[d];
    }
};
int main()
{
  


    return 0;
}

