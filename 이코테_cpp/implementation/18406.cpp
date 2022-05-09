#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int N;
    vector<int> num;
    cin>>N;
    
    while(N>=1){
        num.push_back(N%10);
        N/=10;
    }
    int front = 0;
    int back =0;

    for(int i=0;i<num.size();i++){
        if(i<num.size()/2){
            front+=num[i];
        }
        else{
            back+=num[i];
        }
    }
    if(front==back){
        cout<<"LUCKY";
    }
    else{
        cout<<"READY";
    }

}