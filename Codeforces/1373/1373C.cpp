#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/problemset/problem/1373/C
ll process(string s){
    ll res = 1;
    ll ans = 0;
    ll n = s.length();
    vector<ll> dp(n+1);
    for(int i = 0;i<n;i++){
        if(i==0){
            if(s[i] == '+'){
                dp[i] = 1;
            }
            else dp[i] = -1;
        }
        else{
            if(s[i] == '+')
                dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1] -1;
        }
    }

    for(int i = 0;i<n+1;i++){
        if(dp[i] == (res * -1) && i != n){
            ans = ans + i + 1;
            res++;
        }
        else if(i == n){
            ans = ans + n;
        }
    }
    return ans;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        string s;
        cin >> s;
        ans = process(s);
        cout << ans << "\n";
    }
    
	return 0;
}