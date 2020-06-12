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
    }
    int bfs_snake(T src,T dest){
        //map <T,int>visited;
        map<T,int> distance;
        map<T,T> parent;
        queue<T>q;
        q.push(src);
       //initialize all nodes with infinity initially
        for(auto i:l){
            T node=i.first;
            distance[node]=INT_MAX;
        }
        distance[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T node=q.front();
            q.pop();
            //cout<<node<<" ";
            for(int nrb:l[node]){
                if(distance[nrb]==INT_MAX){
                    q.push(nrb);
                    distance[nrb]=distance[node]+1;
                    parent[nrb]=node;
                }
            }
        }
        for(auto node_pair:l){
            T node=node_pair.first;
            int d=distance[node];
            cout<<" NODE "<<node<<"distance from src "<<d<<endl;
        }
        //Print shortest path to reach end from start by dice
        T temp=dest;
        while(temp!=src){
            cout<<temp<<" <-- ";
            temp=parent[temp];
        }
        cout<<src<<endl;


        return distance[dest];
    }


};

int main() {    
    int board[50]={0};
    //snakes and ladder positions array
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=13;
    board[20]=14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;


  Graph <int> g;

    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j=i+dice;
            j+=board[j];
            if(j<=36){g.addEdge(i,j);}
        }
    }
    g.addEdge(36,36);
    int res=g.bfs_snake(0,36);
    cout<<res<<endl;
}
