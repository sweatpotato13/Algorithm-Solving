#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> res;
    int len = dartResult.length();
    int index = 0;
    for(int i = 0;i < len;i++){
        if(dartResult[i] == 'S'){
            // Do Nothing;   
        }
        else if(dartResult[i] == 'D'){
            res[index-1] *= res[index-1];
        }
        else if(dartResult[i] == 'T'){
            res[index-1] = res[index-1] * res[index-1] * res[index-1];
        }
        else if(dartResult[i] == '*'){
            res[index-1] *= 2;
            if(index > 1)
                res[index-2] *= 2;
        }
        else if(dartResult[i] == '#'){
            res[index-1] *= -1;
        }
        else{
            if(dartResult[i+1] == '0'){
                res.push_back(10);
                i++;
            }
            else{
                res.push_back(dartResult[i] - '0');
            }
            index++;
        }
    }
    for(auto k : res){
        answer += k;
    }
    return answer;
}