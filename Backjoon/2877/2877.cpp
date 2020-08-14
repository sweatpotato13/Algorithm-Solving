#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2877
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    n++;
    vector<ll> v;
    while(n){
        if(n&1) v.push_back(7);
        else v.push_back(4);
        n/=2;
    }
    reverse(all(v));
    for(int i = 1;i<v.size();i++){
        cout << v[i];
    }

    return 0;
}
