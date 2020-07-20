#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/12101
ll dp[12] = {0,};
string ans = "";
void solve(ll n, ll k){
    if(n == 1){
        ans += "1";
        return;
    }
    else if(n == 2){
        if(k ==1)
            ans += "1+1";
        else
            ans += "2";
        return;
    }
    else if(n == 3 && k == 4){
        ans += "3";
        return;
    }
    if(dp[n-1] >= k){
        ans += "1+";
        solve(n - 1, k);
    }
    else if(dp[n-1] + dp[n-2] >= k){
        ans += "2+";
        solve(n - 2, k - dp[n - 1]);
    }
    else{
        ans += "3+";
        solve(n - 3, k - dp[n - 1] - dp[n - 2]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4;i<=11;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    if(dp[n] < k){
        ans = "-1";
    }
    else{
        solve(n,k);
    }
    cout << ans;

    return 0;
}
