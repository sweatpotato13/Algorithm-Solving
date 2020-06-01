#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc169/tasks/abc169_e
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll ans = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    sort(all(a));
    sort(all(b));
    if(n%2 == 0){
        ll ax = b[n/2] + b[(n/2)-1];
        ll in = a[n/2] + a[(n/2)-1];
        ans = ax - in + 1;
    }
    else{
        ll ax = b[n/2];
        ll in = a[n/2];
        ans = ax - in + 1;
    }
    cout << ans << "\n";

    return 0;
}