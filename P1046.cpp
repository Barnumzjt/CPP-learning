#include <iostream>
using namespace std;
int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    int height;
    cin>>height;
    int m=0;
     for(int i=0;i<10;i++){
    if(arr[i]<=height+30){
        m++;
    }
     }
         cout<<m;
         return 0;
}
