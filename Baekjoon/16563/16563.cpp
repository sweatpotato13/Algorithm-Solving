#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/16563
vector<ll> arr(5000001,0);
void getMinFactor() {
    arr[0] = -1;
    arr[1] = -1;
    for(int i = 2;i<=5000000;i++){
        arr[i] = i;
    }
    for(int i = 2;i*i<=5000000;i++){
        if(arr[i] == i){
            for(int j = i*i;j<=5000000;j+=i){
                if(arr[j] == j)
                    arr[j] = i;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
	getMinFactor();
    while(t--){
		vector<ll> ans;
        ll n;
        cin >> n;
        while(n > 1){
            ll temp = arr[n];
            ans.push_back(temp);
            n /= temp;
        }
        sort(all(ans));
        for(auto k : ans){
            cout << k << " ";
        }
        cout << "\n";
    }
    return 0;
}
