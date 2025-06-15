#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
vector<list<pp>> graph;
void add_edge(int src,int dist,int weight){
    graph[src].push_back({dist,weight});
}
int prims(int src){
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    unordered_map<int,int> mp;
    for(int i=0;i<graph.size();i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    int ans=0;
    pq.push({0,src});//w,n
    unordered_set<int> vis;
    while(!pq.empty()){
        auto curr=pq.top();
        int currNode=curr.second;
        int currWeight=curr.first;
        pq.pop();
        if(vis.count(currNode)) continue;
        vis.count(currNode);
        ans+=currWeight;
        for(auto neighbour:graph[currNode]){
            int weight=neighbour.second;
            int node=neighbour.first;
            if(!vis.count(node)&&weight<mp[node]){
                mp[node]=weight;
                pq.push({weight,node});
            }
        }
    }
    return ans;
}
int main(){
    //graph
    graph.resize(7);
    add_edge(0, 1, 3);
    add_edge(0, 3, 2);
    add_edge(1, 2, 4);
    add_edge(3, 2, 1);
    add_edge(1, 4, 2);
    add_edge(4, 5, 5);
    add_edge(4, 6, 1);
    add_edge(5, 6, 3);
    cout<<prims(0)<<endl;
    return 0;
}