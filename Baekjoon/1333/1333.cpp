#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1333
bool isMusic[1000000]={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll idx = 0;
    ll n,l,d;
    ll ans = 0;
    cin >> n >> l >> d;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<l;j++){
            isMusic[idx++] = true;
        }
        for(int j = 0;j<5;j++){
            isMusic[idx++] = false;
        }
    }
    while(1){
        if(!isMusic[ans]){
            break;
        }
        ans += d;
    }
    cout << ans << "\n";
    return 0;
}