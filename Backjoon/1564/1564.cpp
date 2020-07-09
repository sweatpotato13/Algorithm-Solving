#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1564
const ll mod = 1000000000000;
ll facto[1000001]={1,1,2};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 3;i<=n;i++){
        facto[i] = (facto[i-1] * i);
        while(facto[i] % 10 == 0){
            facto[i] /= 10;
        }
        facto[i] %= mod;
    }
    cout.fill('0');
    cout.width(5);
    cout << facto[n] % 100000;

	return 0;
}
