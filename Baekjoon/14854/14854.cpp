#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/14854
ll pow27[31][41];
ll pow_mod(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % m;
        a = a * a % m;
        b /= 2;
    }
    return ans;
}
ll factd27(ll N) {
    vector<ll> c(27);
    while (N >= 1) {
        for (ll i = 0; i < 27; ++i) {
            if (i % 3 == 0) continue;
            ll t = (N - i + 27) / 27;
            c[i] += t;
        }
        N /= 3;
    }
    ll ans = 1;
    for (ll i = 0; i < 27; ++i) {
        if (c[i] >= 1) ans = ans * pow27[i][(c[i] < 18 ? c[i] : c[i] % 18 + 18)] % 27;
    }
    return ans;
}
ll ord3(ll N) {
    ll ans = 0;
    while (N > 0) {
        N /= 3;
        ans += N;
    }
    return ans;
}
ll inv27(ll N) {
    for (ll i = 0; i < 27; ++i) {
        if (i * N % 27 == 1) return i;
    }
    return -1;
}
ll ncr27(ll N, ll K) {
    ll pa = factd27(N);
    ll pb = factd27(K);
    ll pc = factd27(N - K);
    ll cur = pa * inv27(pb) * inv27(pc) % 27;
    ll oa = ord3(N);
    ll ob = ord3(K);
    ll oc = ord3(N - K);
    ll ox = oa - ob - oc;
    if (ox >= 3) return 0;
    for (ll i = 0; i < ox; ++i) cur = cur * 3 % 27;
    return cur;
}
ll ncrp(ll N, ll K, ll P) {
    vector<ll> fact(P), factinv(P);
    fact[0] = 1;
    for (ll i = 1; i < P; ++i) fact[i] = fact[i - 1] * i % P;
    factinv[P - 1] = pow_mod(fact[P - 1], P - 2, P);
    for (ll i = P - 1; i >= 1; --i) factinv[i - 1] = factinv[i] * i % P;
    ll ans = 1;
    while (N > 0 && K > 0) {
        ll n = N % P;
        ll k = K % P;
        if (n < k) return 0;
        ans = ans * fact[n] * factinv[k] * factinv[n - k] % P;
        N /= P;
        K /= P;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    for (ll i = 0; i < 27; ++i) {
        pow27[i][0] = 1;
        for (ll j = 1; j <= 36; ++j) {
            pow27[i][j] = pow27[i][j - 1] * i % 27;
        }
    }

    ll t;
    cin >> t;
    while(t--){
        ll N, K;
        cin >> N >> K;
        ll a27 = ncr27(N, K);
        ll a11 = ncrp(N, K, 11);
        ll a13 = ncrp(N, K, 13);
        ll a37 = ncrp(N, K, 37);
        ll ans = a27;
        for (ll i = 0; i < 11; ++i) {
            if ((ans + i * 27) % 11 == a11) {
                ans += i * 27;
                break;
            }
        }
        for (ll i = 0; i < 13; ++i) {
            if ((ans + i * 27 * 11) % 13 == a13) {
                ans += i * 27 * 11;
                break;
            }
        }
        for (ll i = 0; i < 37; ++i) {
            if ((ans + i * 27 * 11 * 13) % 37 == a37) {
                ans += i * 27 * 11 * 13;
                break;
            }
        }
        cout << ans << '\n';
    }

	return 0;
}
