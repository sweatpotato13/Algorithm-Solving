#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc216/tasks/abc216_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    queue<ll> q;
    vll color[n + 1];

    queue<ll> data[m];
    for (ll i = 0; i < m; i++) {
        ll k;
        cin >> k;
        ll memo[k];
        for (ll j = 0; j < k; j++) {
            cin >> memo[j];
            if (j == k - 1) color[memo[j]].push_back(i);
        }
        for (ll j = k - 2; j >= 0; j--) {
            data[i].push(memo[j]);
        }
    }

    for (ll i = 0; i <= n; i++) {
        if (color[i].size() == 2) q.push(i);
    }

    ll count = 0;
    while (q.empty() == false) {
        ll pos = q.front();
        q.pop();
        count++;
        for (auto x : color[pos]) {
            if (data[x].empty() == false) {
                ll top = data[x].front();
                data[x].pop();
                color[top].push_back(x);
                if (color[top].size() == 2) q.push(top);
            }
        }
    }


    if (count == n)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}