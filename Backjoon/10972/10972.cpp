#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/10972
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    if(next_permutation(all(v))){
        for(int i = 0;i<n;i++){
            cout << v[i] << " ";
        }
    }
    else{
        cout << -1;
    }
    return 0;
}

