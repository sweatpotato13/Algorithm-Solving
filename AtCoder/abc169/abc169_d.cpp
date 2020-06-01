#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc169/tasks/abc169_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll ans = 0;
    ll n;
    cin >> n;
    if(n != 1){
        ll nn = n;
        ll count = 0;
        for (ll i = 2; i * i <= nn; i++) {
            ll loop = 0;
            while (n % i == 0) {
                n /= i;
                loop++;
            }
            for (ll j = 1; j <= loop; j++) {
                loop -= j;
                count++;
            }
        }
        if (n != 1) {
            ans = count + 1;
        } else {
            ans = count;
        }
    }
    cout << ans;
    
 
    return 0;
}