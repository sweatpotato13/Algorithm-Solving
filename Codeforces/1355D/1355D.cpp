#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/problemset/problem/1355/D
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,s;
    cin >> n >> s;
    if(2*n <= s){
        cout << "YES\n";
        for(int i = 0;i<n-1;i++){
            cout << 2 << " ";
            s -= 2;
        }
        cout << s << "\n" << 1;
    }
    else{
        cout <<"NO\n";
    }
	return 0;
}
