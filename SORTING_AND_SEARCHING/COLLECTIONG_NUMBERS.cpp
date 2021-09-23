#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long int ll;

const int N = 1e6 + 10;
int arr[N];

void solve()
{
    // collecting Numbers

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr[x] = i;
    }

    int ctr = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            ctr++;
        }
    }

    cout << ctr << endl;
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
