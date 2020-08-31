#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1344
ld dp[20][20][20] = {0,};
ll che[111] ={0,};
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getChe(100);
    ll a,b;
    cin >> a >> b;
    ld p1 = a/(ld)100, p2 = b/(ld)100;
    dp[1][0][0] = (1-p1) * (1-p2);
    dp[1][0][1] = (1-p1) * p2;
    dp[1][1][0] = p1 * (1-p2);
    dp[1][1][1] = p1 * p2;
    for(int i = 2;i<=18;i++){
        for(int j = 0;j<=i;j++){
            for(int k = 0;k<=i;k++){
                dp[i][j][k] += dp[i-1][j][k] * (1-p1) * (1-p2);
                if(j) dp[i][j][k] += dp[i-1][j-1][k] * p1 * (1-p2);
                if(k) dp[i][j][k] += dp[i-1][j][k-1] * (1-p1) * p2;
                if(j && k) dp[i][j][k] += dp[i-1][j-1][k-1] * p1 * p2;
            }
        }
    }
    ld ans = 0;
    for(int i = 0;i<=18;i++){
        for(int j = 0;j<=18;j++){
            if(che[i] || che[j]){
                ans += dp[18][i][j];
            }
        }
    }
    cout << fixed;
    cout.precision(16);
    cout << ans;

    return 0;
}
