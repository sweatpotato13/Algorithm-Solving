#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/13458
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	ll n,a,b,c;
	cin >> n;
	v.resize(n);
	for(int i = 0 ;i<n;i++){
		cin >> v[i];
	}
	cin >> b >> c;
	for(int i  = 0;i<n;i++){
		int e = v[i];
		e -= b;
		ans++;
		if(e > 0){
			if(e%c == 0){
				ans += e/c;
			}
			else{
				ans += (e/c)+1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}