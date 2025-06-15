#include"include/DSU.h"

DSU::DSU(int n){
    rank.resize(n,0);
    par.resize(n,0);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
}
int DSU::find(int a){
    return par[a]=par[a]==a?a:find(par[a]);
}
void DSU::Union(int a,int b){
    a=find(par[a]);
    b=find(par[b]);
    if(rank[a]>=rank[b]){
        rank[a]++;
        par[b]=a;
    }else{
        rank[b]++;
        par[a]=b;
    }
}
