#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/17943
vector<ll> dp(200001);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vector<ll> v(n+1);
    for(int i = 1;i<n;i++){
        cin >> v[i];
    }
    dp[1] = 0;
    dp[2] = v[1];
    for(int i = 3;i<n+1;i++){
        dp[i] = dp[i-1]^v[i-1];
    }
    for(int i = 0;i<m;i++){
        ll c,x,y,d;
        cin >> c;
        if(c == 0){
            cin >> x >> y;
            ll ans = dp[x] ^ dp[y];
            cout << ans << "\n";
        }
        else{
            cin >> x >> y >> d;
            ll ans = dp[x] ^ dp[y] ^ d;
            cout << ans << "\n";
        }
    }


	return 0;
}
