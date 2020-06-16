#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/10859
bool isPrime(ll num) {
	if (num == 1) return false;
	if (num == 2) return true;
	for (ll i = 2; i*i <= num; i++) {
		if (num % i == 0) 
			return false;
	}
	return true;
}
ll reverse(ll n){
    ll res = 0;
    while(n){
        ll temp = n%10;
        if(temp == 6) temp = 9;
        else if(temp == 9) temp = 6;
        else if(temp == 3 || temp == 4 || temp == 7) return 1;
        res += temp;
        res *= 10;
        n /= 10;
    }
    res /= 10;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] = {"no","yes"};
    bool isAnswer = false;
    ll n;
    cin >> n;
    if(isPrime(n)){
        if(isPrime(reverse(n))){
            isAnswer = true;
        }
    }
    cout << ans[isAnswer];

	return 0;
}