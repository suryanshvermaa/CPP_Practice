#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="suryanshv.ug23.ee@nitp.ac.in";
    // reverse(s.begin(),s.end());
    cout<<s<<endl;
    cout<<s.length()<<endl;//->> returns size of the string same as s.size()
    cout<<s.substr(0,2)<<endl;
    s.push_back('.');
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;
    cout<<"email: "+s<<endl;

    //to_string method converts integer to string
    int a=12456;
    cout<<to_string(a).size()<<endl;
    return 0;
}