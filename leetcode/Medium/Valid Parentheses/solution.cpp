// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return false;
        stack<char> stk;
        for(int i = 0;i<s.size();++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()) return false;
                if(s[i] == ')'){
                    if(stk.top() == '('){
                        stk.pop();
                    }
                    else return false;
                }
                else if(s[i] == '}'){
                    if(stk.top() == '{'){
                        stk.pop();
                    }
                    else return false;
                }
                else if(s[i] == ']'){
                    if(stk.top() == '['){
                        stk.pop();
                    }
                    else return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        else return false;
    }
};