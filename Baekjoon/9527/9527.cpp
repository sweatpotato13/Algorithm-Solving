#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/9527
ll count(ll tempN) {  
    ll n = tempN;
    ll cnt = 0;
    ll times = 1;
    while(n){
        if(tempN & times){
            cnt += tempN % times + (tempN - tempN%(times*2))/2;
        }
        else{
            cnt +=(tempN - tempN % times)/2;
        }
        times = times << 1;
        n = n >> 1;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;
    cin >> a >> b;

    cout << count(b+1) - count(a);

	return 0;
}