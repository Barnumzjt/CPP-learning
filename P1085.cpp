#include <iostream>
using namespace std;
int main(){
    int max=0;
    int id=0;
    for(int i=0;i<7;i++){
        int t1,t2;
        cin>>t1>>t2;
        if(t1+t2>max){
            max=t1+t2;
            id=i;
        }
    }
    if(max>8)cout<<id+1;
    else cout<<0;
    return 0;
}
