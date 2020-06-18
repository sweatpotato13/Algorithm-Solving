#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1367/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        string ans = "";
        string s;
        cin >> s;
        ans += s[0];
        for(int i = 1;i<s.length();i+=2){
            ans += s[i];
        }
        cout << ans << "\n";
    }

	return 0;
}