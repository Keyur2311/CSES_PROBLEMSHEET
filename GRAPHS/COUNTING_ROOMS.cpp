#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

bool visited[1001][1001];
char grid[1001][1001];

void DFS(int i, int j, int n, int m)
{
    if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] != '.' || visited[i][j] == true)
        return;

    visited[i][j] = true;
    DFS(i, j - 1, n, m);
    DFS(i, j + 1, n, m);
    DFS(i + 1, j, n, m);
    DFS(i - 1, j, n, m);
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && visited[i][j] == false)
            {
                DFS(i, j, n, m);
                ans++;
            }
        }
    }

    cout << ans << endl;
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

