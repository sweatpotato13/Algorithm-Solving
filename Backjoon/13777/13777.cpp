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
// https://www.acmicpc.net/problem/13777
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        ll x;
        cin >> x;
        if (!x) break;
        ll high = 50;
        ll low = 1;
        while (low <= high) {
            ll mid = (high + low) / 2;
            cout << mid << " ";
            if (x > mid) {
                low = mid+1;
            } else if (x < mid) {
                high = mid-1;
            } else {
                break;
            }
        }
        cout << "\n";
    }

    return 0;
}