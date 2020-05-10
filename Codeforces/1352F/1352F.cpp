#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://codeforces.com/contest/1352/problem/F
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll t;
	cin >> t;
	while(t--){
		ll a,b,c;
		string ans = "";
		cin >> a >> b >> c;
		if(b == 0){
			if(a > 0){
				for(int i = 0;i<=a;i++) ans += "0";
			}
			else{
				for(int i = 0;i<=c;i++) ans += "1";
			}
		}
		else{
			ans += "10";
			for(int i = 1;i<b;i++){
				if(ans[ans.length()-1] == '1') ans += "0";
				else ans+= "1";
			}
			for(int i = 0;i<a;i++){
				ans.insert(1,1,'0');
			}
			for(int i = 0;i<c;i++){
				ans.insert(0,1,'1');
			}
		}
		cout << ans << "\n";
	}

    return 0;
}
