#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

vector<list<pp>> graph; // pair<node,wieght>
void add_edge(int src,int dist,int weight,bool is_directed=false){
    graph[src].push_back({dist,weight});
    if(!is_directed) graph[dist].push_back({src,weight});
}
pair<vector<int>,int> dijkstra(int src,int dist){
    priority_queue<pp> pq;//w,n
    unordered_map<int,int> mp; //n->dis
    for(int i=0;i<graph.size();i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    pq.push({0,src});
    unordered_set<int> vis;
    vector<int> via(graph.size());
    while(!pq.empty()){
        auto curr=pq.top();
        int currDis=curr.first;
        int currNode=curr.second;
        pq.pop();
        if(vis.count(currNode)) continue;
        vis.count(currNode);
        for(auto neighbour:graph[currNode]){
            int nW=neighbour.second;
            int nN=neighbour.first;
            if(!vis.count(nN)&&nW+currDis<mp[nN]){
                mp[nN]=nW+currDis;
                pq.push({mp[nN],nN});
                via[nN]=currNode;
            }
        }
    }
    return {via,mp[dist]};
}
void printPath(vector<int> &via,int src,int dist){
    if(via[dist]==src) {
        cout<<src<<endl;
        return;
    }
    cout<<via[dist]<<"<-";
    printPath(via,src,via[dist]);
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
    pair<vector<int>,int> ans=dijkstra(0,6);
    cout<<"distance: "<<ans.second<<endl;
    cout<<"path: "<<6<<"<-";
    printPath(ans.first,0,6);
    cout<<endl;
    return 0;
}