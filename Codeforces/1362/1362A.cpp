#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/contest/1362/problem/A
ll removeTwo(ll a){
    while(a%2==0){
        a/=2;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll a,b;
        cin >> a >> b;
        ll r1 = removeTwo(a);
        ll r2 = removeTwo(b);
        if(r1 != r2){
            cout << -1 << "\n";
            continue;
        }
        if(a < b){
            swap(a,b);
        }
        a = a/b;
        while(a >= 8){
            a /= 8;
            ans++;
        }
        if(a > 1) ans++;
        cout << ans << "\n";
    }
    
	return 0;

}