#include<bits/stdc++.h>
using namespace std;
//DSU
int find(vector<int> &par,vector<int> &rank,int x){
    return par[x]=par[x]==x?x:find(par,rank,par[x]);
}
void Union(vector<int> &par,vector<int> &rank,int a,int b){
    a=find(par,rank,a);
    b=find(par,rank,b);
    if(par[a]==par[b]) return;
    if(rank[a]>=rank[b]){
        rank[a]++;
        par[b]=a;
    }else{
        rank[b]++;
        par[a]=b;
    }
}
struct edge
{
    int src;
    int dist;
    int weight;
};
bool compare(edge &e1,edge &e2){
    return e1.weight<e2.weight;
}
int krushkals(int n,vector<edge> &edges){
    vector<int> par(n);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    vector<int> rank(n,0);
    sort(edges.begin(),edges.end(),compare);
    int ans=0;
    for(int i=0;i<edges.size();i++){
        if(find(par,rank,edges[i].src)!=find(par,rank,edges[i].dist)) {
            ans+=edges[i].weight;
            Union(par,rank,edges[i].src,edges[i].dist);
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> edges(m,edge());
    while(m--){
        int src,dist,weight;
        cin>>src>>dist>>weight;
        edges[m-1]={src,dist,weight};
    }
    cout<<krushkals(n,edges)<<endl;
    return 0;
}