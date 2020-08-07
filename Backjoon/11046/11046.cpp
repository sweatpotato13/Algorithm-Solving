#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11046
ll a[2020202] ={0,};
void manachers(vector<ll> s){
    ll r = 0, p = 0;
    for (int i = 0; i < s.size(); i++){
        if (i <= r)
            a[i] = min(a[2 * p - i], r - i);
        else
            a[i] = 0;
        while (i - a[i] - 1 >= 0 && i + a[i] + 1 < s.size() && s[i - a[i] - 1] == s[i + a[i] + 1])
            a[i]++;
        if (r < i + a[i]){
            r = i + a[i];
            p = i;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v;
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        v.push_back(-1);
        v.push_back(e);
    }
    v.push_back(-1);
    manachers(v);
    ll m;
    cin >> m;
    for(int i = 0;i<m;i++){
        ll s,e;
        cin >> s >> e;
        ll size = e-s+1;
        if(size == 1) cout << 1 << "\n";
        else{
            if(a[s+e-1] >= size)
                cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }

    return 0;
}
