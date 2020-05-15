#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/contest/1353/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n == 1){
            cout << 0 << "\n";
        }
        else{
            cout << min(2, n-1) * m << "\n";
        }

    }

	return 0;
}
