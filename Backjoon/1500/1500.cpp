#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1500
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> list;
    ll ans = 1;
    ll s,k;
    cin >> s >> k;
    ll div = s/k;
    ll mod = s%k;
    for(int i = 0;i<k-mod;i++){
        list.push_back(div);
    }
    for(int i = 0;i<mod;i++){
        list.push_back(div+1);
    }
    for(auto k : list){
        ans *= k;
    }
    cout << ans;
	return 0;
}