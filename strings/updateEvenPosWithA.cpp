#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter String: ";
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0) s[i]='a';
    }
    cout<<s<<endl;
    return 0;
}