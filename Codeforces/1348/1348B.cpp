#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// http://codeforces.com/contest/1348/problem/B
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        set<int> s;
        for(int i = 0;i<n;i++){
            int e;
            cin >> e;
            s.insert(e);
        }
        if(s.size() > k){
            cout << -1 << "\n";
            continue;
        }
        cout << n * k << "\n";
        for(int i = 0;i<n;i++){
            for (int e:s)
              cout << e << " ";
            for(int j = 0;j<k-s.size();j++)
                cout << 1 << " ";
        }
        cout << "\n";
    }    
    
	return 0;
}