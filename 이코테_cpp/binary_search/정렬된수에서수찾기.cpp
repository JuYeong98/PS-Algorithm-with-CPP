#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N , M;
    cin >> N >> M;
    vector<int> v;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int cnt = upper_bound(v.begin() , v.end(), M) - lower_bound(v.begin() , v.end(), M);
    cout<<cnt;
    
    
}