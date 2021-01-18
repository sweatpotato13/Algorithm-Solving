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
// https://www.acmicpc.net/problem/13728
ll f[101010]={0,};
ll mod = 1e9+7;
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n;
	f[1] = 1;
	for(int i = 2;i<=100100;i++){
		f[i] = (f[i-1] + f[i-2])%mod;
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans += f[gcd(1+i,n+1)];
		ans %= mod;
	}
	cout << ans;

    return 0;
}