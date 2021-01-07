#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/problemset/problem/1360/D
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll ans = 1e9+1;
		ll n,k;
		cin >> n >> k;
		for(ll i = 1;i*i<=n;i++){
			if(n%i==0){
				if(i <= k){
					ans = min(ans, n/i);
				}
				if(n/i <= k){
					ans = min(ans, i);
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}