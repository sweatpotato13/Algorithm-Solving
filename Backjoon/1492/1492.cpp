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
// https://www.acmicpc.net/problem/1492
ll c[55][55] ={0,};
ll d[55] ={0,};
ll MOD = 1e9+7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }
const int N = 60;
ll inv[N], fact[N], ifact[N];
void pre()
{
    inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = mul(MOD - MOD / i, inv[MOD % i], MOD);
        fact[i] = mul(i * 1ll, fact[i - 1], MOD);
        ifact[i] = mul(inv[i], ifact[i - 1], MOD);
    }
    return;
}
ll nCr(ll n, ll r)
{
    if (n >= 0 && r >= 0 && n >= r)
        return mul(fact[n], mul(ifact[r], ifact[n - r], MOD), MOD);
    return 0;
}
ll powmod(ll a, ll b, ll p){
	ll res = 1;
	a = a % p;
	if(a == 0) return 0;
	while(b > 0){
		if(b & 1){
			res = (res * a) % p;
		}
		b = b >> 1;
		a = (a*a)%p;
	}
	return res;
}
ll inve(ll a, ll m) {
	ll m0 = m, y = 0, x = 1;
	if (m == 1)	return 0;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += m0;
	return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n,k;
	cin >> n >> k;
	pre();
	d[0] = n;
	d[1] = (n*(n+1)/2) % MOD;
	for(int i = 2;i<=k;i++){
		d[i] = powmod(n+1,i+1,MOD) - 1;
		for(int j=2;j<=i+1;j++){
			d[i] = (d[i] - nCr(i+1,j) * d[i-j+1]) % MOD;
		}
		d[i] = (d[i] * inve(i+1,MOD))%MOD;
		if(d[i] < 0) d[i] += MOD;
	}
	cout << d[k];

    return 0;
}