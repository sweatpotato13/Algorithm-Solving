#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2133
ll dp[31] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    dp[0] = 1;
    for(int i = 2;i<31;i+=2){
        dp[i] = dp[i-2];
        for(int j = 2;j<=i;j+=2){
            dp[i] += (2*dp[i-j]);
        }
    }
    cout << dp[n];

    return 0;
}
