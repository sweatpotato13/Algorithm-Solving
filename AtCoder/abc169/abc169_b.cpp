#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc169/tasks/abc169_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 1;
    ll limit = 1e18;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        if(v[i] == 0)
            ans = 0;
    }
    if(ans != 0){
        for(int i = 0;i<n;i++){
            ll e = v[i];
            if(ans > limit / e){
                ans = -1;
                break;
            }
            else{
                ans *= e;
            }
        }
    }
    cout << ans;

    return 0;
}