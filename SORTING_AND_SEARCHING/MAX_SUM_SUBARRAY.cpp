
#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

void solve()
{
    // MAXIMUM SUBARRAY SUM (KADANE'S ALGORITHM)

    // IF ALL ELEMENTS OF ARRAY ARE NEGATIVE, THIS CODE WILL ALSO WORK.

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll mx = LLONG_MIN;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];
        mx = max(mx, sum);

        if (sum < 0)
            sum = 0;
    }

    cout << mx << endl;
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
