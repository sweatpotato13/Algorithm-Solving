#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/13900
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	ll arr[101010] ={0,};
	ll n;
	cin >> n;
	vll v(n);
	rep(i,n){
		cin >> v[i];
	}
	ll ans = 0;
	arr[0] = v[0];
	for(int i = 1;i<n;i++){
		arr[i] = arr[i-1] + v[i];
	}
	rep(i,n){
		ans += v[i] * (arr[n-1] - arr[i]);
	}
	cout << ans;
	
		
}
