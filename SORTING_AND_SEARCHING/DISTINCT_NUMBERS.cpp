#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << (int)st.size() << endl;
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
