#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
vector<ll> ans;
// https://codeforces.com/contest/1328/problem/B
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s(n, 'a');
		for(int i = n-2; i>=0;i--){
			if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;
                break;
            }
            k -= (n - i - 1);
		}
	}
 
	return 0;
}
