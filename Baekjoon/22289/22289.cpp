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
// https://www.acmicpc.net/problem/22289
const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();

    for (int i = 1, j = 0; i < S; i++) {
        int bit = S / 2;

        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if (i < j) swap(v[i], v[j]);
    }

    for (int k = 1; k < S; k *= 2) {
        double angle = (inv ? PI / k : -PI / k);
        cpx dir(cos(angle), sin(angle));

        for (int i = 0; i < S; i += k * 2) {
            cpx unit(1, 0);

            for (int j = 0; j < k; j++) {
                cpx a = v[i + j];
                cpx b = v[i + j + k] * unit;

                v[i + j] = a + b;
                v[i + j + k] = a - b;

                unit *= dir;
            }
        }
    }

    if (inv)
        for (int i = 0; i < S; i++) v[i] /= S;
}

vector<cpx> mul(vector<cpx> &v, vector<cpx> &u) {
    int S = 2;
    while (S < v.size() + u.size()) S *= 2;

    v.resize(S);
    FFT(v, false);
    u.resize(S);
    FFT(u, false);

    vector<cpx> w(S);
    for (int i = 0; i < S; i++) w[i] = v[i] * u[i];
    FFT(w, true);

    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    if (!a.compare("0") || !b.compare("0")) {
        cout << 0;
        return 0;
    }

    vector<cpx> v, u;
    for (int i = 0; i < a.length(); i++) v.push_back(cpx(a[i] - '0', 0));
    for (int i = 0; i < b.length(); i++) u.push_back(cpx(b[i] - '0', 0));

    reverse(all(v));
    reverse(all(u));

    vector<cpx> w = mul(v, u);

    vector<int> ans(w.size());

    for (int i = 0; i < ans.size(); i++) ans[i] = round(w[i].real());

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] < 10) continue;

        if (i < ans.size() - 1)
            ans[i + 1] += ans[i] / 10;
        else
            ans.push_back(ans[i] / 10);

        ans[i] %= 10;
    }

    reverse(all(ans));

    int i = 0;
    while (ans[i] == 0) i++;
    if (i >= ans.size()) cout << 0 << "\n";

    while (i < ans.size()) {
        cout << ans[i];
        i++;
    }
    cout << "\n";

    return 0;
}