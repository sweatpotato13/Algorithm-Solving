#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/11423
ll che[10000001] ={0,};
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getChe(10000000);
    while(true){
        ll m,n;
        cin >> m >> n;
        if(cin.eof()) break;
        ll ans = 0;
        for(int i = m;i<=n;i++){
            if(che[i]) ans++;
        }
        cout << ans << "\n\n";
    }

	return 0;
}
