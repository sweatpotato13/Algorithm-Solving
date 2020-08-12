#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    for(int i = 2;i<=2500;i++){
        for(int j = 2;j<=2500;j++){
            if(i*2 + (j-2)*2 == brown && (i-2)*(j-2) == yellow ){
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    return answer;
}
