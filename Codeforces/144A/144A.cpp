#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/144/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
    cin >> n;
    vector<ll> v(n);
    ll ans = 0;
    ll mx = -1;
    ll mn = 101;
    ll max_index;
    ll min_index;
    for(int i = 0;i<n;i++){
        cin >> v[i];
        if(v[i] <= mn){
            mn = v[i];
            min_index = i;
        }
        if(v[i] > mx){
            mx = v[i];
            max_index = i;
        }
    }
    if(max_index < min_index){
        ans = max_index + (n-1 - min_index);
    }
    else{
        ans = max_index + (n-1 - min_index) - 1;
    }
    cout << ans << "\n";

	return 0;

}