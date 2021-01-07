#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/1385/D
ll solve(string s, char ch){
    if(s.size() == 1){
        return s[0] != ch;
    }
    ll m = s.size() / 2;
    ll l = solve(string(s.begin(), s.begin() + m), ch+1);
	l += s.size() / 2 - count(s.begin() + m, s.end(), ch);
	ll r = solve(string(s.begin() + m, s.end()), ch + 1);
	r += s.size() / 2 - count(s.begin(), s.begin() + m, ch);
    return min(l,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s,'a') << "\n";
    }

    return 0; 
}
