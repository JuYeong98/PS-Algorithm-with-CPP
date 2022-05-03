#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int size =food_times.size();
    int index = 0;
    int min = *min_element(food_times.begin(), food_times.end());
    int minus= size * min;
    if(minus > k){
        for(int i=0;i<size;i++){
            food_times[i] -=min;
        }  
        for(int i =0;i<k+1;i++){
        while(1){
            if(food_times[index]!=0){
                food_times[index]--;
                if(i==k){
                    break;
                }
                index++;
                if(index==size)
                {
                    index=0;
                }
                break;
            }
            else{
                index ++;
                if(index==size)
                {
                    index=0;
                }
            }
        }
    }
    }
    else{
        for(int i =0;i<k+1;i++){
        while(1){
            if(food_times[index]!=0){
                food_times[index]--;
                if(i==k){
                    break;
                }
                index++;
                if(index==size)
                {
                    index=0;
                }
                break;
            }
            else{
                index ++;
                if(index==size)
                {
                    index=0;
                }
            }
        }
    }
    }
    
    return index+1;
}

int main(void){
    vector<int> food_times ={3, 1, 2};
    long long k = 5;
    cout<<solution(food_times , k);
}