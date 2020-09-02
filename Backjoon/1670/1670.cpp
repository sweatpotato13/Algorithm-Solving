#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1670
const ll mod = 987654321;
ll dp[10001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 0;
    dp[0] = 1;
    dp[2] = 1;
    for(int i = 4;i<=n;i+=2){
        ll temp = 0;
        for(int j = 0;j<=i;j+=2){
            temp += dp[j] * dp[i-j-2];
            temp %= mod;
        }
        dp[i] = temp%mod;
    }
    cout << dp[n];

    return 0;
}
