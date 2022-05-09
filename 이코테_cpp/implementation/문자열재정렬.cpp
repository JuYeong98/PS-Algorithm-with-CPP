#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(void){
    string N;
    vector<string> alpha;
    vector<char> number;
    cin>>N;
    for(int i=0;i<N.size();i++){
        if(N[i]<=97 && N[i]>=65){
            string tmp;
            tmp.push_back(N[i]);
            alpha.push_back(tmp);
        }
        else if(N[i]<=57 && N[i]>=48){
            number.push_back(N[i]);
        }
    }
    sort(alpha.begin(), alpha.end());
    int sum= 0;
    for(int i=0;i<number.size();i++){
        sum+=int(number[i])-48;
    }
    string answer = "";
    for(int i=0;i<alpha.size();i++){
        answer +=alpha[i];
    }
    answer+=to_string(sum);
    cout<<answer;

}