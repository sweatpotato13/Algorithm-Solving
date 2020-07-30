#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1153
ll che[1000001] ={0,};
vector<ll> prime;
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
void solve(ll n){
    for(int i = 2;i<=n/2;i++){
        if(che[i] && che[n-i]){
            cout << i << " " << n-i;
            return;
        }
    }
    return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    getChe(1000000);
    ll n;
    cin >> n;
    if(n < 8){
        cout << -1;
    }
    else{
        if(n % 2 == 0){
            cout << 2 << " " << 2 << " ";
            n -= 4;
            solve(n);
        }
        else{
            cout << 2 << " " << 3 << " ";
            n -= 5;
            solve(n);
        }
    }

	return 0;
}
