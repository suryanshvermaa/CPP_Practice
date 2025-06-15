#include<bits/stdc++.h>
#include"include/Graph.h"
using namespace std;
vector<int> topo_sort(vector<list<int>> &graph){
    vector<int> depen(graph.size());
    for(auto node: graph){
        for(auto neighbour:node){
            depen[neighbour]++;
        }
    }
    //kahn's algorithm
    queue<int> qu;
    for(int i=0;i<graph.size();i++){
        if(depen[i]==0) qu.push(i);
    }
    while(!qu.empty()){
        int curr=qu.front();
        qu.pop();
        //neighbours
        for(auto neighbour:graph[curr]){
            depen[neighbour]--;
            if(depen[neighbour]==0){
                qu.push(neighbour);
            }
        }
    }
    return depen;
}
int main(){
    Graph* graph=new Graph(8);
    graph->add_edge(1,2,false);
    graph->add_edge(2,4,false);
    graph->add_edge(2,6,false);
    graph->add_edge(2,5,false);
    graph->add_edge(2,3,false);
    graph->add_edge(3,5,false);
    graph->add_edge(5,6,false);
    graph->add_edge(4,6,false);
    graph->add_edge(6,7,false);
    vector<int> ans=topo_sort(graph->graph);
    for(auto el:ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}