#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/15824
ll mod = 1e9+7;
ll power(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp&1){
            res = res * base % mod;
        }
        exp /= 2;
        base = base * base % mod;
    }
    return res;
}
ll md(ll a, ll m){
    return ((a%m)+m)%m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ll ax = power(2, i);
		ans += (v[i] % mod) * ax % mod;
		ll in = power(2, n-i-1);
		ans -= (v[i] % mod) * in % mod;
		ans = md(ans, mod);
    }
    cout << ans;

	return 0;
}
