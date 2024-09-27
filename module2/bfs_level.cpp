#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int l[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    l[src]=0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                l[child]=l[par]+1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    memset(l, -1, sizeof(l));
    bfs(src);
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<l[i]<<endl;
    }
    return 0;
}