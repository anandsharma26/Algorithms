#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{    
    map<T,list<T>> l;
public:
    void addEdge(int x,int y){
      l[x].push_back(y);
      l[y].push_back(x);
    }
    void bfs(T src){
        //map <T,int>visited;
        map<T,int> distance;
        queue<T>q;
        q.push(src);
       
        
        for(auto i:l){
            T node=i.first;
            distance[node]=INT_MAX;
        }
        distance[src]=0;

        while(!q.empty()){
            T node=q.front();
            q.pop();
            //cout<<node<<" ";
            for(int nrb:l[node]){
                if(distance[nrb]==INT_MAX){
                    q.push(nrb);
                    distance[nrb]=distance[node]+1;
                }
            }
        }
        for(auto node_pair:l){
            T node=node_pair.first;
            int d=distance[node];
            cout<<" NODE "<<node<<"distance from src "<<d<<endl;
        }
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
    g.bfs(0);
    
}
