#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/contest/1352/problem/E
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll ans = 0;
		ll n;
		cin >> n;
		vector<ll> v(n);
		vector<ll> isVisited(n+1,0);
		for(int i = 0;i<n;i++){
			cin >> v[i];
			isVisited[v[i]]++;
		}
		for(int l = 0;l<n;l++){
			ll sum = 0;
			for(int r=l;r<n;r++){
				sum += v[r];
				if(l == r) continue;
				if(sum <= n){
					ans += isVisited[sum];
					isVisited[sum] = 0;
				}
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
