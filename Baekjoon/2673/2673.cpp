#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2673
ll dp[101][101] = {0,};
ll in[101][101] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
        ll s,e;
        cin >> s >> e;
        in[s][e] = in[e][s] = 1;
    }
    for(int i = 1;i<=100;i++)
        for(int j = i-1;j>0;j--)
            for(int k = i; k>j; k--)
                dp[i][j] = max(dp[i][j],max(dp[i][k]+dp[k-1][j],dp[i-in[i][j]][k-in[i][j]]+dp[k-in[i][j]-1][j+in[i][j]]+in[i][j]));


    cout << dp[100][1];
    return 0;
}
