#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int cur_x = 1;
    int cur_y =1;

    int N;
    vector<int> seq;

    cin>>N;
    string input;
    cin>>input;
    for(int i=0;i<input.size();i++){
        if(input[i]=='U'){
            if(cur_y ==1){
                continue;
            }
            else{
                cur_y-=1;
            }
        }
        else if(input[i]=='D'){
            if(cur_y ==N){
                continue;
            }
            else{
                cur_y+=1;
            }
        }
        else if(input[i]=='L'){
            if(cur_x==1){
                continue;
            }
            else{
                cur_x-=1;
            }
        }
        else{
            if(cur_x ==N){
                continue;
            }
            else{
                cur_x+=1;
            }
        }
    }
    cout<< "x : "<< cur_x<< "  y : "<<cur_y <<endl;
}