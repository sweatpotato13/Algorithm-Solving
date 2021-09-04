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
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/20149
void find_intersection(pll A, pll B, pll C, pll D) {
    ld px = (A.X * B.Y - A.Y * B.X) * (C.X - D.X) -
            (A.X - B.X) * (C.X * D.Y - C.Y * D.X);
    ld py = (A.X * B.Y - A.Y * B.X) * (C.Y - D.Y) -
            (A.Y - B.Y) * (C.X * D.Y - C.Y * D.X);
    ld p = (A.X - B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X - D.X);

    if (p == 0) {
        if (B == C && A <= C)
            cout << B.X << " " << B.Y << '\n';
        else if (A == D && C <= A)
            cout << A.X << " " << A.Y << '\n';
    } else {
        ld x = px / p;
        ld y = py / p;

        cout << fixed;
        cout.precision(9);
        cout << x << " " << y;
    }
}

ll CCW(pll A, pll B, pll C) {
    ll tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
    tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

    if (tmp > 0)
        return 1;
    else if (tmp == 0)
        return 0;
    else if (tmp < 0)
        return -1;
}

void solve(pll A, pll B, pll C, pll D) {
    ll ans1 = CCW(A, B, C) * CCW(A, B, D);
    ll ans2 = CCW(C, D, A) * CCW(C, D, B);

    if (ans1 == 0 && ans2 == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);

        if (A <= D && B >= C) {
            cout << 1 << '\n';
            find_intersection(A, B, C, D);
        } else
            cout << 0 << '\n';
    } else {
        if (ans1 <= 0 && ans2 <= 0) {
            cout << 1 << '\n';
            find_intersection(A, B, C, D);
        } else
            cout << 0 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, y;
    vector<pll> v;
    rep(i, 4) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    solve(v[0], v[1], v[2], v[3]);

    return 0;
}
