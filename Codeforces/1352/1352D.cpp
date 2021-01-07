#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// http://codeforces.com/contest/1352/problem/D
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll sum = 0;
		ll cnt = 1, a=0, b=0;
		ll min = 0;
		ll n;
		cin >> n;
		deque<ll> d;
		for(int i = 0;i<n;i++){
			ll e;
			cin >> e;
			sum += e;
			d.push_back(e);
		}
		a = d.front();
		d.pop_front();
		min = a;
		sum -= a;
		while(!d.empty()){
			cnt++;
			if(sum <= min){
				b += sum;
				break;
			}
			else{
				ll sumB = 0;
				while(sumB <= min){
					sumB += d.back();
					d.pop_back();
				}
				b += sumB;
				sum -= sumB;
				min = sumB;
			}
			if(!d.empty()){
				cnt++;
				if(sum <= min){
					a += sum;
					break;
				}
				else{
					ll sumA = 0;
					while(sumA <= min){
						sumA += d.front();
						d.pop_front();
					}
					a += sumA;
					sum -= sumA;
					min = sumA;
				}		
			}
		}
		cout << cnt << " " << a << " " << b << "\n";
	}

	return 0;
}