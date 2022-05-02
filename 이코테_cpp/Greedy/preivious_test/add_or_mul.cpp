#include <iostream>
using namespace std;

int main(void){
    string N;
    cin>>N;
    int result =N[0]-'0';
    for(int i=0;i<N.size()-1;i++){
        if((result) * (N[i+1]-'0') >(result) + (N[i+1]-'0') ){
            result *=(N[i+1]-'0');
        }
        else{
            result +=(N[i+1]-'0');
        }
    }
    cout<<result<<endl;
}