#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int N;
    vector<int> ropes;
    vector<int>weights;
    cin>>N;
    for(int i=0; i<N;i++){
        int x;
        cin>>x;
        ropes.push_back(x);
    }
    sort(ropes.begin(),ropes.end(),greater<int>());
    int max =-100;
    int weight_sum=0;
    for(int i=0;i<ropes.size();i++){
        weights.push_back(ropes[i]*(i+1));
    }
    int max_num = *max_element(weights.begin(), weights.end());
    cout<<max_num;
}