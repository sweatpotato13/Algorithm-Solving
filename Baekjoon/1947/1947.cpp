#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1947
const ll mod = 1e9;
ll dp[1000001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4;i<=n;i++){
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2]))%mod;
    }
    cout << dp[n];

    return 0;
}
