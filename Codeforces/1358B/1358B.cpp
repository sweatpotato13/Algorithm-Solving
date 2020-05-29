#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// http://codeforces.com/problemset/problem/1358/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        sort(all(v));
        ll ans = -1;
        for(int i = n-1;i>=0;i--){
            if(v[i] <= i+1){
                ans = i+2;
                break;
            }
        }
        if(ans == -1){
            ans = 1;
        }
        cout << ans << "\n";

    }

    return 0;
}