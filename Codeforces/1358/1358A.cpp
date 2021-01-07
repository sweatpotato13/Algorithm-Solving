#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/1358/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n,m;
        cin >> n >> m;
        if((n*m)%2 == 1){
            ans = (n*m+1)/2;
        }
        else{
            ans = n*m/2;
        }
        cout << ans << "\n";
    }

    return 0;
}