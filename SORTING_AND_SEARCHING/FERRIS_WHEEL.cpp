#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        if (v[l] + v[r] > x)
        {
            r--;
            ans++;
        }
        else
        {
            l++;
            r--;
            ans++;
        }

        if (r - l == 1)
        {
            if (v[l] + v[r] <= x)
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
            break;
        }
        else if (l == r)
        {
            ans++;
            break;
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

