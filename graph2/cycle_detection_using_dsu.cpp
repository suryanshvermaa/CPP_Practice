#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
    }
    int find(int x){
        return parent[x]=(parent[x]==x?x:find(parent[x]));
    }
    void Union(int a,int b){
        a=find(parent[a]);
        b=find(parent[b]);
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }else{
            rank[b]++;
            parent[a]=b;
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    while(m--){
        int src,dist;
        cin>>src>>dist;
        if(dsu.find(src)==dsu.find(dist)) cout<<"Cycle detected";
        dsu.Union(src,dist);
    }
    return 0;
}