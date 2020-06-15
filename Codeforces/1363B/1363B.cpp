#pragma warning(disable : 4996)
#include <bits/stdc++.h>
extern "C" {
#include <quadmath.h>
}
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/problemset/problem/1363/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll ones = 0;
        ll zeros = 0;
        string s;
        cin >> s;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '0') zeros++;
            else ones++;
        }
        ans = min(ones,zeros);
        ll done1 = 0;
        ll done0 = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '0'){
                done0++;
                zeros--;
            }
            else{
                done1++;
                ones--;
            }
            ans = min(ans, zeros + done1);
            ans = min(ans, done0 + ones);
        }
        cout << ans << "\n";
    }

	return 0;
}