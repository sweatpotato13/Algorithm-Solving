#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/14330
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll idx = 1;
	ll t;
	cin >> t;
	while(t--){
		ll ans = 1;
		vector<char> v[5];
		string s;
		cin >> s;
		for(int i = 0;i<s.length();i++){
			char e = s[i];
			for(int j = -1;j<=1;j++){
				if(i+j >= 0 && i+j < s.length()){
					v[i+j].push_back(e);
				}
			}
		}
		for(int i = 0;i<s.length();i++){
			sort(all(v[i]));
			dup(v[i]);
			ans = (ans * v[i].size()) % mod;
		}
		cout << "Case #" << idx << ": ";
		cout << ans << "\n";
		idx++;
	}

	return 0;
}