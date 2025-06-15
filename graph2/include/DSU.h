#include<vector>
using namespace std;
#ifndef DSU_H
#define DSU_H

class DSU{
private:
    vector<int> rank;
    vector<int> par;
public:
    DSU(int n);
    int find(int a);
    void Union(int a,int b);
};

#endif