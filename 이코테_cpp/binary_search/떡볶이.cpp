#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long sum_of_left(vector<int>a, int cut)
{
    long long sum = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] - cut>0){
            sum +=a[i]- cut;
        }
    }
    return sum;
}
int main(void){
    int solution=0;
    int N, M;
    cin >> N >> M;
    vector<int> ddeok;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        ddeok.push_back(x);
    }
    sort(ddeok.begin(), ddeok.end());
    int s = 0;
    int e = ddeok[N-1];
    while(s<=e){
        int mid = (s+e) / 2;
        long long sum = 0;
        sum = sum_of_left(ddeok, mid);
        if(sum == M){
            solution = mid;
        }
        else if(sum<M){
            e = mid-1;
        }
        else{
            s = mid +1;
        }
    }
    cout<<solution;
}