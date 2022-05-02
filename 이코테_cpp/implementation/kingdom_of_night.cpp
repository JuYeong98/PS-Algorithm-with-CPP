#include <iostream>
using namespace std;

int convert(char input){
    return input-96;
}

int main(void){
    string input;
    cin>>input; 
    int x,y;
    x= convert(input[0]);
    y= int(input[1])-48;
    int move_x[8] = {2,2,-2,-2,1,1,-1,-1};
    int move_y[8]= {1,-1,1,-1,2,-2,2,-2};

    int result=0;
    for(int i=0;i<8;i++){
        if(x+move_x[i]>=1 && x+move_x[i]<9){
            if(y+move_y[i]>=1 && y+move_y[i]<9){
                result ++;
            }
        }
    }
    cout<<result;
}