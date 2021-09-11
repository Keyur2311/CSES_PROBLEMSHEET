
#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

char grid[1001][1001];
bool visited[1001][1001];

bool isValid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
void solve()
{

    int n, m;
    cin >> n >> m;

    int srcrow = -1, srccol = -1;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                srcrow = i;
                srccol = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({srcrow, srccol});
    visited[srcrow][srccol] = true;

    map<pair<int, int>, pair<pair<int, int>, char>> mp;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int i = p.first;
        int j = p.second;

        for (int k = 0; k < 4; k++)
        {
            int adjx = i + row[k];
            int adjy = j + col[k];

            if (isValid(adjx, adjy, n, m) && visited[adjx][adjy] == false && (grid[adjx][adjy] == '.' || grid[adjx][adjy] == 'B'))
            {
                visited[adjx][adjy] = true;
                char c;

                if (adjx - i == 1)
                    c = 'D';
                if (i - adjx == 1)
                    c = 'U';
                if (adjy - j == 1)
                    c = 'R';
                if (j - adjy == 1)
                    c = 'L';

                mp[{adjx, adjy}] = {{i, j}, c};

                if (grid[adjx][adjy] == 'B')
                {
                    pair<int, int> end = {adjx, adjy};
                    string res = "";
                    while (true)
                    {
                        res += mp[end].second;
                        end = mp[end].first;

                        if (end.first == srcrow && end.second == srccol)
                        {
                            break;
                        }
                    }

                    reverse(res.begin(), res.end());
                    cout << "YES" << endl;
                    cout << res.length() << endl;
                    cout << res << endl;
                    return;
                }

                visited[adjx][adjy] = true;
                q.push({adjx, adjy});
            }
        }
    }

    cout << "NO" << endl;
    return;
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
