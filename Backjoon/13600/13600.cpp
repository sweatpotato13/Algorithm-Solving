#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/13600
ll facto[11] ={1,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    cin >> n;
    for(int i =1;i<11;i++){
        facto[i] = facto[i-1] * i;
    }
    ll s = 0;
    for(int i = 1;i<11;i++){
        if(n < facto[i]){
            s = i-1;
            break;
        }
    }
    while(n){
        while(n >= facto[s]){
            n -= facto[s];
            ans++;
        }
        s--;
    }
    cout << ans;

	return 0;
}