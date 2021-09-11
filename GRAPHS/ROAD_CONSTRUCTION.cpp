#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 200001;
int parent[N];
int sz[N];

class DSU
{
public:
    void makeSet(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;

    DSU d;
    d.makeSet(n);

    int mx = 1, cc = n;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        if (d.findParent(x) != d.findParent(y))
        {
            d.Union(x, y);
            cc -= 1;
        }

        mx = max(sz[d.findParent(x)], mx);

        cout << cc << " " << mx << endl;
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
