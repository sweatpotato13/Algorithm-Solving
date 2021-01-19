#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/17134
using base = complex<double>;
constexpr auto pi = 3.14159265358979323846264;
void fft(vector<base>& A, bool inv) {
    int n = A.size(), j = 0;
    vector<base> roots(n / 2);
    for (int i = 1; i < n; i++) {
        int bit = (n >> 1);
        while (j >= bit) j -= bit, bit >>= 1;
        j += bit;
        if (i < j) swap(A[i], A[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for (int i = 0; i < n / 2; i++) roots[i] = base(cos(ang * i), sin(ang * i));
    for (int i = 2; i <= n; i <<= 1) {
        int step = n / i;
        for (int j = 0; j < n; j += i)
            for (int k = 0; k < i / 2; k++) {
                base u = A[j + k], v = A[j + k + i / 2] * roots[step * k];
                A[j + k] = u + v;
                A[j + k + i / 2] = u - v;
            }
    }
    if (inv)
        for (int i = 0; i < n; i++) A[i] /= n;
}
vector<ll> multiply(vector<ll>& a, vector<ll>& b) {
    vector<base> A(a.begin(), a.end()), B(b.begin(), b.end());
    int n = 2;
    while (n < a.size() + b.size()) n <<= 1;
    A.resize(n);
    B.resize(n);
    fft(A, 0);
    fft(B, 0);
    for (int i = 0; i < n; i++) A[i] *= B[i];
    fft(A, 1);
    vector<ll> ret(n);
    for (int i = 0; i < n; i++) ret[i] = (int)round(A[i].real());
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> a(1000000, 1), b(1000000);
    for (int i = 2; i < 1000; i++)
        if (a[i]) {
            for (int j = i * i; j < 1000000; j += i) a[j] = 0;
        }
    vector<ll> prime;
    for (int i = 2; i < 500000; i++) {
        if (a[i]) prime.push_back(i);
    }
    a[0] = a[1] = a[2] = 0;
    for (int i = 0; i < prime.size(); i++) {
        for (int j = i; j < prime.size(); j++) {
            if (1LL * prime[i] * prime[j] >= 1000000) break;
            if (prime[i] & 1 && prime[j] & 1) continue;
            b[prime[i] * prime[j]] = 1;
        }
    }
    vector<ll> ans = multiply(a, b);
    ll t;
    cin >> t;
    tc(t) {
        ll n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}