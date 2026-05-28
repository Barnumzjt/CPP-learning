#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> vec;
    int n;
    while(cin>>n&&n!=0){
        vec.push_back(n);
    }
    for(int i=vec.size()-1;i>=0;i--){
        cout<<vec[i];
        if(i!=0)cout<<" ";
    }
    return 0;
}
