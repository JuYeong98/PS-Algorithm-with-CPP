#include <iostream>

using namespace std;
int main(void){
    string N;
    cin>>N;
    int count =0;
    string a= "AAAA";
    string b="BB";

    for(int i=0;i<N.size();){
        if(N[i]=='.')
            i++;
        else if(N.substr(i,4)=="XXXX"){
            N.replace(i,4,a);
            i+=4;
        }
        else if(N.substr(i,2)=="XX"){
            N.replace(i,2,b);
            i+=2;
        }
        else{
            cout<<-1;
            return 0;
        }
    }
    cout<<N;
}