#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {//N은 스테이지의 개수 
    int size = stages.size();
    vector<int> pass;
    sort(stages.begin(), stages.end());
    
    for(int i=1;i<=N;i++){
        for(int j = 0;j<stages.size();i++){
            if(i==stages[j]){
                pass.push_back(size-j);
            }
        }
    }
}