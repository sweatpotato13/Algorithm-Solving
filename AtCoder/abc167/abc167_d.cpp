#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc167/tasks/abc167_d
map<ll, ll> m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    vector<ll> v(n+1);
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    ll pos = 1;
    ll t = 1;
    while(m[pos] == 0){
        m[pos] = t;
        t++;
        pos =v[pos];
    }
    if(k > n){
        k -= m[pos]-1;
        ll temp = k % (t-m[pos]);
        ll curr = pos;
        while(temp){
            curr = v[curr];
            temp--;
        }
        cout << curr;
    }
    else{
        ll curr = 1;
        while(k){
            curr = v[curr];
            k--;
        }
        cout << curr;
    }
	return 0;

}