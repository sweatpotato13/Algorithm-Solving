#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/10867
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;

    cin >> n;
    map<ll,ll> m;
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        m[e]++;
    }
    for(auto k : m){
        cout << k.first << " ";
    }

	return 0;
}
