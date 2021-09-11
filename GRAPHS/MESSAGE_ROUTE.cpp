#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

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
    queue<int> q;
    q.push(1);
    vis[1] = true;
    map<int, int> parent;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == n)
        {
            vector<int> ans;
            int end = curr;
            while (parent[end] != 1)
            {
                ans.push_back(end);
                end = parent[end];
            }
            ans.push_back(end);
            ans.push_back(1);

            reverse(ans.begin(), ans.end());

            cout << int(ans.size()) << endl;
            for (int i = 0; i < (int)ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return;
        }
        for (auto it : graph[curr])
        {
            if (vis[it] == false)
            {
                vis[it] = true;
                parent[it] = curr;
                q.push(it);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

