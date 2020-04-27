#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/13323
priority_queue<ll> pq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	ll n;
	cin >> n;
	for(int i = 0;i<n;i++){
		ll e;
		cin >> e;
		e -= i;
		pq.push(e);
		if(e < pq.top()){
			ans += pq.top()-e;
			pq.pop();
			pq.push(e);
		}
	}
	cout << ans << "\n";
	return 0;
}