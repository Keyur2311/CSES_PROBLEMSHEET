#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

ll totalCost(vector<int> v, int k)
{
    ll cost = 0;

    for (auto it : v)
    {
        cost += (abs(it - k));
    }
    return cost;
}
void solve()
{
    // sticks length

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int mid = v[n / 2]; // median
    cout << totalCost(v, mid) << endl;
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
