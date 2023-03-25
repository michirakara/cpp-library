#include <iostream>
#include <vector>
template<class T>
struct edge{
    int from,to;
    T cost;
    
    edge(int to,T cost):from(-1),to(to),cost(cost){}
    edge(int from,int to,T cost):from(from),to(to),cost(cost){}

    edge &operator=(const int &x){
        to=x;
        return *this;
    }
};

template<class T>
using Edges = std::vector<edge<T>>;

template<class T>
using WeightedGraph = std::vector<Edges<T>>;
using UnweightedGraph = std::vector<std::vector<int>>;

UnweightedGraph input_graph(int N,int M,bool directed=false,bool one_origin=true){
    UnweightedGraph ret(N);
    for(int i=0;i<M;i++){
        int from,to;std::cin>>from>>to;
        if(one_origin)from--,to--;
        ret[from].push_back(to);
        if(!directed)ret[to].push_back(from);
    }
    return ret;
};

template<class T>
WeightedGraph<T> input_wgraph(int N,int M,bool directed=false,bool one_origin=true){
    WeightedGraph<T> ret(N);
    for(int i=0;i<M;i++){
        int from,to;T cost;std::cin>>from>>to>>cost;
        if(one_origin)from--,to--;
        ret[from].emplace_back(from,to,cost);
        if(!directed)ret[to].emplace_back(to,from,cost);
    }
    return ret;
};
