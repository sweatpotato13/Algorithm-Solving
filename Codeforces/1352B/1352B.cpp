#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// http://codeforces.com/contest/1352/problem/B
string ans[2] = {"NO","YES"};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		bool isCorrect = false;
		ll n,k;
		vector<ll> v;
		cin >> n >> k;
		if(n < k){
			isCorrect = false;
		}
		else if(n == k){
			isCorrect = true;
			for(int i = 0;i<n;i++)
				v.push_back(1);
		}
		else{
			if((n - (k-1)) > 0 && (n - (k-1))%2 == 1){
				isCorrect = true;
				for(int i = 0;i<k-1;i++)
					v.push_back(1);
				v.push_back((n - (k-1)));
			}
			else if((n - 2*(k-1)) > 0 && (n - 2*(k-1))%2==0){
				isCorrect = true;
				for(int i = 0;i<k-1;i++)
					v.push_back(2);
				v.push_back((n - 2*(k-1)));
			}
			else
				isCorrect = false;
		}
		if(isCorrect){
			cout << ans[isCorrect] << "\n";
			for(int i = 0;i<v.size();i++){
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		else{
			cout << ans[isCorrect] << "\n";
		}
	}

	return 0;
}
