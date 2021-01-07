#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/1399/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] = {"NO","YES"};
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        sort(all(v));
        bool isAnswer = true;
        for(int i = 1;i<n;i++){
            if(v[i] - v[i-1] > 1){
                isAnswer = false;
                break;
            }
        }
        cout << ans[isAnswer] << "\n";
    }




    return 0;
}
