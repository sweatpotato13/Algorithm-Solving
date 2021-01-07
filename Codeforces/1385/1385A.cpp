#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/1385/A
string ans[2] = {"NO", "YES"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        vector<ll> v(3);
        for(int i = 0;i<3;i++){
            cin >> v[i];
        }
        sort(all(v));
        bool isAnswer = true;
        if(v[1] != v[2]){
            isAnswer = false;
        }
        cout << ans[isAnswer] << "\n";
        if(isAnswer){
            cout << v[0] << " " << v[0] << " " << v[2] << "\n";
        }
    }

    return 0; 
}
