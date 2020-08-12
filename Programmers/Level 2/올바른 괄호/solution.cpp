#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(auto k : s){
        if(k == '('){
            st.push(k);
        }
        else if(k == ')'){
            if(st.empty()){
                answer = false;
                break;
            }
            else{
                if(st.top() == '('){
                    st.pop();
                }
            }
        }
    }
    if(!st.empty()) answer = false;
    return answer;
}
