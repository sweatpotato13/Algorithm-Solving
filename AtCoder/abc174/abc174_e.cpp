#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc174/tasks/abc174_e
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    ll l = 0;
    ll h = 1e9+1;
    ll ans = 0;
    while(l <= h){
        ll mid = (l+h)/2;
        if(mid < 1){
            ans = 1;
            break;
        }
        ll temp = 0;
        for(auto k : v)
            temp += ((k+mid-1)/mid) - 1;
        if(temp <= k){
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid+1;
    }
    cout << ans;

    return 0; 
}