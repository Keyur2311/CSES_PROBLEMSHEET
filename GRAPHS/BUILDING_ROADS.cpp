#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

void DFS(int src, vector<int> graph[], bool *vis)
{
    vis[src] = true;
    for (auto it : graph[src])
    {
        if (vis[it] == false)
        {
            DFS(it, graph, vis);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool vis[n + 1] = {0};
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            v.push_back(i);
            DFS(i, graph, vis);
        }
    }

    if ((int)v.size() == 1)
    {
        cout << "0" << endl;
        return;
    }

    cout << int(v.size()) - 1 << endl;
    for (int i = 0; i < int(v.size()) - 1; i++)
    {
        cout << v[i] << " " << v[i + 1] << endl;
    }
}

int main()
{
    //FLASH
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

