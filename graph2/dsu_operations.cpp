#include<bits/stdc++.h>
#include"DSU.h"
using namespace std;
int main(){
    int n,m;
    //n->elements & n->no.of queries
    cin>>n>>m;
    DSU dsu(n);
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            dsu.Union(x,y);
        }else{
            int x;
            cin>>x;
            cout<<dsu.find(x)<<endl;
        }
    }
    return 0;
}