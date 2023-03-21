#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/10815
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll val = 10000000;
    ll n;
    cin >> n;
    map<ll,ll> m;
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        m[e+val]++;
    }
    ll mm;
    cin >> mm;
    for(int i =0;i<mm;i++){
        ll e;
        cin >> e;
        if(m[e+val] != 0){
            cout << 1 << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
	return 0;
}
