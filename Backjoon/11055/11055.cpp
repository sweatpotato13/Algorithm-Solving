#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11055
ll dp1[1001] ={0,};
ll dp2[1001] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        dp2[i] = v[i];
    }
    ll ans = dp2[0];
    for(int i = 0;i<n;i++){
        dp1[i] = 1;
        for(int j = 0;j<i;j++){
            if(v[i] > v[j] && dp1[j]+1 > dp1[i]){
                dp1[i] = dp1[j]+1;
                dp2[i] = max(dp2[i], dp2[j]+v[i]);
            }
            ans = max(ans, dp2[i]);
        }
    }
    cout << ans;

    return 0;
}
