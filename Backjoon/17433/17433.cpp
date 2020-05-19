#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://acmicpc.net/problem/17433
ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    else return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans;
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> a;
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        if(n > 1){
            sort(all(v));
            for(int i = 0;i<n-1;i++){
                a.push_back(v[i+1] - v[i]);
            }
            ans = a[0];
            for(int i = 0;i<a.size();i++){
                ans = gcd(ans, a[i]);
            }
        }
        else{
            ans = v[0];
        }
        if(ans)
            cout << ans << "\n";
        else cout << "INFINITY\n";
    }

	return 0;
}
