#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> is_div_num(int n){
    vector<int> num;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)
            num.push_back(i);
    }
    return num;
}

void zip(string input, int n){
    vector<string> tmp;
    cout<<"num: "<<n<<endl; 
    for(int i=0;i<input.size();i=i+n){
        //cout<<"i:"<<i<<"  t:"<<i+n<<"  ";
        string t = input.substr(i,n);
        cout<<t<<"  ";
        tmp.push_back(t);   
    }
    cout<<endl;
    int straight =1;
    string t;
    for(int i=0;i<tmp.size()-1;i++){
        if(tmp[i] == tmp[i+1]){
            straight++;
            if(i==tmp.size()-2){
                t+=to_string(straight);
                t+=tmp[i];
            }
        }
        else{
            if(straight!=1){
                t+=to_string(straight);
                t+=tmp[i];
                if(i==tmp.size()-2){
                    t+=tmp[i+1];
                }
            }
            else if(straight==1){
                t+=tmp[i];
                if(i==tmp.size()-2){
                    t+=tmp[i+1];
                }
            }
            straight=1;
        }
    }
    cout<<t<<endl;
     
}
int main(void){
    string N;
    vector<int> num_of_zip;
    cin>>N;
    vector<int> num =  is_div_num(N.size());
    int straight=0;
    for(int i=0;i<num.size();i++){
        zip(N , num[i]);
    }
}