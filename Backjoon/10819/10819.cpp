#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/10819
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    ll ans = -1;
    do{
        ll temp = 0;
        for(int i = 1;i<n;i++){
            temp += abs(v[i] - v[i-1]);
        }
        ans = max(ans, temp);
    }while(next_permutation(all(v)));
    
    cout << ans;

    return 0;
}
