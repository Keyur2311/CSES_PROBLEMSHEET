#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

bool checkForBipartite(int src, vector<int> graph[], int *color)
{
    for (auto it : graph[src])
    {
        if (color[it] == -1)
        {
            if (color[src] == 1)
                color[it] = 2;
            else
                color[it] = 1;

            if (!checkForBipartite(it, graph, color))
                return false;
        }
        else if (color[it] == color[src])
            return false;
    }
    return true;
}
bool isBipartite(vector<int> graph[], int n, int *color)
{

    for (int i = 1; i <= n; i++)
        color[i] = -1;

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!checkForBipartite(i, graph, color))
            {
                return false;
            }
        }
    }
    return true;
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

    int color[n + 1];
    if (!isBipartite(graph, n, color))
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }
    cout << endl;
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

