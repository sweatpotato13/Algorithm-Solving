#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/aising2020/tasks/aising2020_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ans = 0;
    for(int i = 0;i<n;i++){
        cin >> v[i];
        if(i%2 == 0 && v[i]%2==1)
            ans++;
    }
    cout << ans;


	return 0;
}
