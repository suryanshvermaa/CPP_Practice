#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="I am a student of NIT Patna.";
    stringstream ss(s);
    string sso;
    while(ss>>sso){
        cout<<sso<<endl;
    }
    return 0;
}