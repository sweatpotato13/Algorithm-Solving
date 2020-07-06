#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc173/tasks/abc173_e
ll mod = 1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    ll l = 0, r = n-1;
    ll ans = 1;
    if(k & 1){
        if(a[n-1] < 0){
            ans = 1;
            for(int i = n-1;i>=n-k;i--){
                ans *= a[i];
                ans %= mod;
            }
            if(ans < 0)
                cout << ans + mod;
            else 
                cout << ans;
            return 0;
        }
        r--;
        k--;
    }

    while(k){
        ll lv = a[l] * a[l+1];
        ll rv = a[r] * a[r-1];
        if(lv < rv)
            r -= 2;
        else 
            l += 2;
        k -= 2;
    }
    ans = 1;
    for(int i = 0;i<l;i++){
        ans *= a[i];
        ans %= mod;
    }
    for(int i = r+1;i<n;i++){
        ans *= a[i];
        ans %= mod;
    }
    if(ans < 0) 
        cout << ans + mod;
    else 
        cout << ans;

	return 0;
}
