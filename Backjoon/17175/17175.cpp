#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/17175
ll dp[51] = {1,1,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 2;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2] + 1) % 1000000007;
    }
    cout << dp[n];
    return 0;
}
