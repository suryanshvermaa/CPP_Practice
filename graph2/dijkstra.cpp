#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

vector<list<pp>> graph; // pair<node,wieght>
void add_edge(int src,int dist,int weight,bool is_directed=false){
    graph[src].push_back({dist,weight});
    if(!is_directed) graph[dist].push_back({src,weight});
}


int dijkstra(int src,int dist){
    priority_queue<pp,vector<pp>,greater<pp>> pq; //(dist,node)
    vector<int> dis(graph.size()+1,1e9);
    pq.push({0,src});
    while(!pq.empty()){
        auto [distance,node]=pq.top();
        pq.pop();
        for(auto [n,w]:graph[node]){
            if(w+distance<dis[n]){
                pq.push({w+distance,n});
                dis[n]=w+distance;
            }
        }
    }
    return dis[dist];
}

int main(){
    graph.resize(7,list<pp> ());
    add_edge(0,2,2);
    add_edge(0,1,7);
    add_edge(1,3,2);
    add_edge(2,3,1);
    add_edge(2,4,2);
    add_edge(4,5,5);
    add_edge(4,6,3);
    add_edge(5,6,1);
    cout<<"distance: "<<dijkstra(0,6)<<endl;
    cout<<endl;
    return 0;
}