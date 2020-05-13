#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// http://codeforces.com/contest/1350/problem/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        ll ans = 0;
        cin >> n;
        vector<ll> dp(n+1);
        vector<ll> v(n+1);
        for(int i = 1;i<=n;i++){
            cin >> v[i];
        }
        for(int i = 1;i<=n;i++){
            for(int j = i*2;j<=n;j+=i){
                if(v[i] < v[j]){
                    dp[j] = max(dp[i]+1,dp[j]);
                    if(dp[j] > ans) ans = dp[j];
                }
            }
        }
        
        
        cout << ans+1 << "\n";
   }
 
	return 0;
}