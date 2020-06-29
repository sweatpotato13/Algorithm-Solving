#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1374/problem/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top() == '('){
                    if(s[i] == ')'){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        ll ans = st.size()/2;
        cout << ans << "\n";
    }
    
	return 0;
}
