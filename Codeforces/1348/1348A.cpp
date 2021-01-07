#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// http://codeforces.com/contest/1348/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll a = 0;
        ll b = 0;
        ll n;
        cin >> n;
        vector<ll> v(n+1);
        v[0] = 1;
        for(int i = 1;i<=n;i++){
            v[i] = v[i-1]*2;
        }
        for(int i = 1;i<=n;i++){
            if(i <= (n/2)-1) a+=v[i];
            else if(i <= n-1) b+=v[i];
            else a+=v[i];
        }
        cout << abs(a-b) << "\n";
    }
    
 
    return 0;
}
