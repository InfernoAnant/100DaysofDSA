/*Given an undirected graph with V vertices and E edges, check whether it 
contains any cycle or not*/

#include <iostream> 
#include <vector> 
using namespace std; 

const int MAX_V=1e5+5; 
vector<int>sdj[MAX_V]; 
vector<bool> visited; 

bool dfs(int node, int parent){ 
    visited[node]=true; 
    for(int neighbor:sdj[node]){ 
        if(!visited[neighbor]){ 
            if(dfs(neighbor, node)) return true; 
        }else if(neighbor != parent){ 
            return true; 
        } 
    } 
    return false; 
} 

int main(){ 
    int V,E; 
    cin >> V >> E; 
    visited.resize(V, false); 
    for(int i=0;i<E;++i){ 
        int u,v; 
        cin>>u>>v; 
        sdj[u].push_back(v); 
        sdj[v].push_back(u); 
    } 
    for(int i=0;i<V;i++){ 
        if(!visited[i]){ 
            if(dfs(i, -1)){ 
                cout<<"Contain cycle"<<endl; 
                return 0;
            } 
        } 
    } 
    cout<<"Does not contain cycle"<<endl; 
    return 0; 
}