#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/5648
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        reverse(all(v[i]));
    }
    vector<ll> ans(n);
    for(int i = 0;i<n;i++){
        ans[i] = atoll(v[i].c_str());
    }
    sort(all(ans));
    for(int i = 0;i<n;i++){
        cout << ans[i] << "\n";
    }

    



	return 0;
}
