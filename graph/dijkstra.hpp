#include "../graph/graph-template.hpp"

#include <queue>
#include <utility>
#include <functional>

template<class T>
std::vector<T> dijkstra(WeightedGraph<T> &graph,int start=0){
    int n=(int)graph.size();
    std::vector<T> dist(n,(T)-1);
    std::vector<bool> ok(n,false);

    std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<std::pair<T,int>>> Q;
    dist[start]=0;
    Q.push({dist[start],start});

    while(!Q.empty()){
        int pos=Q.top().second;Q.pop();
        if(ok[pos])continue;
        ok[pos]=true;
        for(int i=0;i<(int)graph[pos].size();i++){
            if(dist[graph[pos][i].to]==-1 || dist[graph[pos][i].to]>dist[pos]+graph[pos][i].cost){
                dist[graph[pos][i].to]=dist[pos]+graph[pos][i].cost;
                Q.push({dist[graph[pos][i].to],graph[pos][i].to});
            }
        }
    }

    return dist;
}