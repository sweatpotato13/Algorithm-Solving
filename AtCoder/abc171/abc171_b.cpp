#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc171/tasks/abc171_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll ans = 0;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    for(int i = 0;i<k;i++){
        ans += v[i];
    }
    cout << ans;
    
	return 0;
}
