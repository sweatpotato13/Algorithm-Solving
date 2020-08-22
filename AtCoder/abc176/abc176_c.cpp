#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc176/tasks/abc176_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    stack<ll> s;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(s.empty()){
            s.push(v[i]);
        }
        else{
            if(s.top() <= v[i]){
                s.push(v[i]);
            }
            else{
                ans += (s.top() - v[i]);
            }
        }
    }
    cout << ans;


    return 0;
}

