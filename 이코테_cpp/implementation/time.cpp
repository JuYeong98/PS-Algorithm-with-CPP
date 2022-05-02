#include <iostream>
using namespace std;
bool is_in(int num , int n){
    if(num ==n){
        return true;
    }
    else{
        if(num %10 == n){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(void){
    int N;
    cin>>N;
    int result = 0;
    for(int i=0;i<24;i++){
        if(is_in(i,N)){
            result += 3600;
            continue;
        }
        for(int j=0;j<60;j++){
            if(is_in(j,N)){
                result +=60;
                continue;
            }
            for(int k=0;i<60;k++){
                if(is_in(k,N)){
                    result +=1;
                }
            }
        }
    }
    cout << N<<"이 포함된 시간은 "<< result<<" 초이다. "<<endl;
}