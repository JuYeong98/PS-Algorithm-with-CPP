#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin>>N;
    int a,b=0;
    int answer =0;
    if(N<5){
        if(N%2==1)
            answer=-1;
        else
            answer = N/2;       
    }
    else{
        if((N%5)%2==1){
        a= (N/5)-1;
        b= (N-(a*5))/2;
        answer = a+b;
    }
        else{
            a= N/5;
            b= (N%5)/2;
            answer = a+b;
        }
    }
    cout<<answer;
}