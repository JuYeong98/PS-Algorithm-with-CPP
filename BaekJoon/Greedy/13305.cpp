#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    vector<long long> prices;
    vector<long long> kms;
    long long result =0;
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
        long long x;
        cin>>x;
        kms.push_back(x);
    }
    for(int i=0;i<N;i++){
        long long x;
        cin>>x;
        prices.push_back(x);
    }
    int MIN = 1000000001;
    
    for(int i=0;i<kms.size();i++){
        if(prices[i]< MIN){
            MIN = prices[i];
            result +=MIN * kms[i];
        }
        else{ //현재 가격이 더 큰 경우 
            result +=MIN * kms[i];
        }
    }
    cout<<result;
}