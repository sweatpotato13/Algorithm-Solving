#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/contest/1362/problem/D
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans;
        ll n;
        cin >> n;
        ans = 2*n;
        while(n){
            if(n % 2 == 1){
                ans--;
            }
            n/=2;
        }
        cout << ans << "\n";
    }
    
	return 0;

}