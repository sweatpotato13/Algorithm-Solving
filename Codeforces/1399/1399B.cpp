#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/1399/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        ll a_min = INT_MAX, b_min = INT_MAX;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            a_min = min(a[i],a_min);
        }
        for(int i = 0;i<n;i++){
            cin >> b[i];
            b_min = min(b[i], b_min);
        }
        ll ans = 0;
        for(int i = 0;i<n;i++){
            if(a[i] != a_min && b[i] != b_min){
                ll temp = (a[i] - a_min) < (b[i] - b_min) ? a[i] - a_min : b[i] - b_min;
                ans += temp;
                a[i] -= temp;
                b[i] -= temp;
            }
        }
        for(int i = 0;i<n;i++){
            if(a[i] != a_min){
                ans += a[i] - a_min;
            }
            else if(b[i] != b_min){
                ans += b[i] - b_min;
            }
        }
        cout << ans << "\n";
    }




    return 0;
}
