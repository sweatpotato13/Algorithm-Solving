#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// http://codeforces.com/contest/1352/problem/A
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		ll cnt = 0;
		ll tens = 1;
		vector<ll> v;
		cin >> n;
		while(n != 0){
			ll temp = n%10;
			if(temp != 0){
				cnt++;
				temp *= tens;
				v.push_back(temp);
			}
			tens *= 10;
			n /= 10;
		}
		cout << cnt << "\n";
		for(int i = 0;i<cnt;i++)
			cout << v[i] << " ";
		cout << "\n";
	}

	return 0;
}
