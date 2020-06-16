#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/17425
vector<ll> dp(1000001);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> f(1000001,1);
    for(int i = 2;i<= 1000000;i++){
        for(int j = 1;i*j<=1000000;j++){
            f[i*j] += i;
        }
    }
    for(int i = 1;i<=1000000;i++){
        dp[i] = dp[i-1] + f[i];
    }
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << dp[n] << "\n";
    }

	return 0;
}