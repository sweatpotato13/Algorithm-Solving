#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/contest/1352/problem/G
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> ans;
		if(n < 4){
			ans.push_back(-1);
		}
		else{
			for(int i = n;i>=1;i--){
				if(i % 2) ans.push_back(i);
			}
			ans.push_back(4);
			ans.push_back(2);
			for(int i = 6;i<=n;i++){
				if(i % 2 == 0) ans.push_back(i);
			}
		}
		for(int i = 0;i<ans.size();i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

    return 0;
}
