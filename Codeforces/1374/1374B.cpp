#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1374/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n;
        cin >> n;
        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        map<ll,ll> m;
        for(int i = 2;i<=3;i++){
            while(n % i == 0){
                m[i]++;
                n /= i;
            }
        }
        if(n != 1 || m[3] == 0 || m[3] < m[2]){
            cout << -1 << "\n";
            continue;
        }
        ans = abs(m[2] - m[3]) + max(m[2],m[3]);
        cout << ans << "\n";
    }
    
	return 0;
}
