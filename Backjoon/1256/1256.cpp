#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1256
ll mod = 1e9;
ll dp[111][111] = {0,};
string ans = "";
void getWord(ll a, ll z, ll skip){
    if(a == 0){
        for(int i = 0;i<z;i++){
            ans += 'z';
        }
        return;
    }
    if(z == 0){
        for(int i = 0;i<a;i++){
            ans += "a";
        }
        return;
    }
    ll idx = dp[a-1][z];
    if(idx >= skip){
        ans += 'a';
        getWord(a-1,z,skip);
    }
    else{
        ans += 'z';
        getWord(a,z-1,skip-idx);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][1] = 2;
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 1;
                continue;
            }
        ll a = dp[i][j] * (i+j+1) / (i+1);
        ll b = dp[i][j] * (i+j+1) / (j+1);
        dp[i+1][j] = a <= mod ? a : mod+1;
        dp[i][j+1] = b <= mod ? b : mod+1;
    }
    ll n,m,k;
    cin >> n >> m >> k;
    if(k > dp[n][m]){
        cout << -1;
        return 0;
    }
    else getWord(n,m,k);
    cout << ans;

    return 0;
}
