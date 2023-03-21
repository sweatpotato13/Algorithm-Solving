#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/12728
ll dp[1000001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 6;
    dp[2] = 28;
    for(int i = 3;i<=1000000;i++){
        dp[i] = ((dp[i-1]*6 - dp[i-2]*4) + 1000)%1000;
    }
    ll t;
    cin >> t;
    ll idx = 1;
    while(t--){
        ll e;
        cin >> e;
        cout << "Case #" << idx++ << ": ";
        ll ans;
        if(e > 104)
            ans = dp[(e-4)%100+4];
        else
            ans = dp[e];
        cout.fill('0');
        cout.width(3);
        cout << (ans-1+1000)%1000 << "\n";
    }

	return 0;
}
