#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/6159
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,s;
    cin >> n >> s;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    ll l = 0;
    ll r = n-1;
    while(v[l] + v[r] > s){
        r--;
    }
    ll ans = 0;
    while(l < r){
        ans += (r-l);
        l++;
        while(v[l] + v[r] > s){
            r--;
        }  
    }
    cout << ans;

	return 0;
}
