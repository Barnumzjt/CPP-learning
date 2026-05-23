#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int len=0;
    int arr[11]={0};
    if(n==0){
        cout<<0;
    }
    if(n<0){
        cout<<"-";
        n=-n;
    }
    while(n){
        arr[len++]=n%10;
        n/=10;
    }
    bool flag=0;
    for(int i=0;i<len;i++){
        if(!flag&&arr[i]!=0){
            flag=1;
        }
        if(flag)cout<<arr[i];
    }
    return 0;
}
