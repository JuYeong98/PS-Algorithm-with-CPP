#include <iostream>
using namespace std;

int main(void){
    int N , M ;
    int arr[1000][100]  = {0,};
    int result =0;
    int min = 1000000;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(arr[i][j]<min){
                min = arr[i][j];
            }
        }
        if(result < min){
            result = min;
        }
    }
    cout <<result ;
}