#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/11191
ll basis[61] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        for(int j = 60;j>=0;j--){
            if((v[i] >> j) % 2 == 1){
                if(basis[j] == 0){
                    basis[j] = v[i];
                    break;
                }
                else{
                    v[i] ^= basis[j];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 60;i>=0;i--){
        ans = max(ans, ans ^ basis[i]);
    }
    cout << ans;


	return 0;
}
