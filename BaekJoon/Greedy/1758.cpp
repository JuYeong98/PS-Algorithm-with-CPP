#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int N;
    cin>>N;

    vector<long long> moneys;
    for(int i=0;i<N;i++){
        long long x;
        cin>>x;
        moneys.push_back(x);
    }   
    long long result=0;
    sort(moneys.begin(), moneys.end(),greater<int>());
    for(int i=0;i<N;i++){
        long long money = moneys[i]-i;
        if(money >0){
            result +=money;
        }else{
            continue;
        }
    }
    cout<<result<<endl;
}