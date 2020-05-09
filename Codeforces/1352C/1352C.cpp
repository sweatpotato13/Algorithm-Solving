#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// http://codeforces.com/contest/1352/problem/C
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		if(n < k){
			ll temp = k / (n-1);
			ll re = k % (n-1);
			ll c = n*temp;
			if(re == 0){
				cout << c-1 << "\n";
			}
			else{
				cout << c + re << "\n";
			}
		}
		else if(n == k){
			cout << n+1 << "\n";
		}
		else{
			cout << k << "\n";
		}
	}

	return 0;
}
