#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/contest/1003/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll ans = 1;
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	sort(all(v));
	ll cnt = 1;
	for(int i = 1;i<n;i++){
		if(v[i-1] == v[i]){
			cnt ++;
			if(cnt > ans)
				ans = cnt;
		}
		else{
			cnt = 1;
		}
	}
	cout << ans << "\n";
    return 0;
}
