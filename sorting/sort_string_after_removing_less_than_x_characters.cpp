#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="asyzxcvdheamzzyl";
    string ansS="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='x') ansS+=s[i];
    }
    sort(ansS.begin(),ansS.end());
    cout<<ansS<<endl;
    return 0;
}