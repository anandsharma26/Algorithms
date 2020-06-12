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
    void dfs(){
        map<T,bool> visited;
        int count=0;
        for(auto i:l){
            T node=i.first;
            visited[node]=false;
        }
        for(auto i:l){
            T node=i.first;
            if(!visited[node]){
                cout<<"Component "<<count<<" ---> ";
                dfs_helper(node,visited);
                cout<<endl;
                count++;
            }
        }
        cout<<count<<endl;
    }


};

int main() {    
Graph <int> g;
  g.addEdge(0,1);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(0,4);
  g.addEdge(5,6);
  g.addEdge(6,7);
  g.addEdge(8,8);
  g.addEdge(9,9);
  g.dfs();

 
}
