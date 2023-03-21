#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/2824
ll che[40001] ={0,};
vector<ll> p;
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
    for(int i = 2;i<=num;i++){
        if(che[i] != 0)
            p.push_back(i);
    }
}
map<ll,ll> A;
map<ll,ll> B;
void setMapA(ll e){
    for(auto k : p){
        while(e % k == 0){
            A[k]++;
            e /= k;
        }
    }
    if(e != 1){
        A[e]++;
    }
}
void setMapB(ll e){
    for(auto k : p){
        while(e % k == 0){
            B[k]++;
            e /= k;
        }
    }
    if(e != 1){
        B[e]++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isOver = false;
    getChe(40000);
    ll MOD = 1000000000;
    ll ans = 1;
    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        setMapA(e);
    }
    ll m;
    cin >> m;
    for(int i = 0;i<m;i++){
        ll e;
        cin >> e;
        setMapB(e);
    }
    for(auto k : A){
        if(B[k.first] == 0) continue;
        ll temp = min(k.second, B[k.first]);
        for(int i = 0;i<temp;i++){
            ans *= k.first;
            if(ans > MOD){
                isOver = true;
                ans %= MOD;
            }
        }
    }

    if(isOver){
        ans %= MOD;
	    cout.width(9);
	    cout.fill('0');
    }
    cout << ans << '\n';
    

	return 0;
}