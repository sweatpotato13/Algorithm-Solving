#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/271/A
bool isDistinct(ll y){
    bool res = true;
    ll cnt[10] ={0,};
    while(y){
        ll temp = y%10;
        if(cnt[temp] != 0){
            res = false;
            break;
        }
        else{
            cnt[temp]++;
        }
        y /= 10;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 999;
    ll y;
    cin >> y;
    for(int i = y+1;i<=10000;i++){
        if(isDistinct(i)){
            ans = i;
            break;
        }
    }
    cout << ans;

	return 0;
}