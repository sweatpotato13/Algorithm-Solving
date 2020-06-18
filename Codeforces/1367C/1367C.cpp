#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1367/problem/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        for(int i = 0;i<s.length();){
            ll j = i+1;
            for(;j<n && s[j] != '1';j++);
            ll left = s[i] == '1' ? k : 0;
			ll right = j < n && s[j] == '1' ? k : 0;
			ll len = j - i;
			if (left == k) {
				len--;
			}
			len -= left + right;
			if (len > 0) {
				ans += (len + k) / (k + 1);
			}
			i = j;
        }
        cout << ans << "\n";

    }

	return 0;
}