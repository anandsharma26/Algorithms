#include <bits/stdc++.h>
using namespace std;
template<typename T>
//SNAKES and LADDER challenge
class Graph{    
    map<T,list<T>> l;
public:
    //directed edges 
    void addEdge(int x,int y){
      l[x].push_back(y);
      l[y].push_back(x);
    }
    //recursive dfs function
    void dfs_helper(T src,map<T,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(T nbr:l[src]){
            if(!visited[nbr]){dfs_helper(nbr,visited);}
        }
    }
    //main dfs function
    void dfs(T src){
        map<T,bool> visited;
        for(auto i:l){
            T node=i.first;
            visited[node]=false;
        }
        dfs_helper(src,visited);
        
    }


};

int main() {    
Graph <int> g;
  g.addEdge(0,1);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.dfs(0);

 
}
