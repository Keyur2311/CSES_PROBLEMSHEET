#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v[i].first = val;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    int l = 0, r = n - 1;

    while (l < r)
    {
        if (v[l].first + v[r].first == x)
        {
            cout << v[l].second + 1 << " " << v[r].second + 1 << endl;
            return;
        }

        if (v[l].first + v[r].first < x)
        {
            l++;
        }
        else
        {
            r--;
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
