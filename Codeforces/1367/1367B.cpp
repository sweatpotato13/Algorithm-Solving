#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1367/problem/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll wrong1 = 0;
        ll wrong0 = 0;
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<n;i++){
            if(i %2 == 0 && i%2 != a[i]%2){
                wrong0++;
            }
            if(i %2 == 1 && i%2 != a[i]%2){
                wrong1++;
            }
        }
        if(wrong0 != wrong1) ans = -1;
        else ans = wrong0;
        cout << ans << "\n";
    }

	return 0;
}