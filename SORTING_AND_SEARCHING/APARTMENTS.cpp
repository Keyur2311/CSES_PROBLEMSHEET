#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            i++;
            j++;
            ans++;
        }

        else if ((a[i] - b[j]) > k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << ans << endl;
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

