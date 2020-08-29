#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/155/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    ll min = v[0];
    ll max = v[0];
    ll ans = 0;
    for(int i = 1;i<n;i++){
        if(v[i] < min){
            min = v[i];
            ans++;
        }
        if(v[i] > max){
            max = v[i];
            ans++;
        }
    }
    cout << ans;

    return 0;
}


