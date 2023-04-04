#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/scc.hpp"

int main(){
    int V,E;
    cin>>V>>E;
    UnweightedGraph G=input_graph(V,E,true,false);
    SCC scc;scc.build(G);
    int Q;
    cin>>Q;
    while(Q--){
        int u,v;
        cin>>u>>v;
        cout<<(scc[u]==scc[v]?1:0)<<endl;
    }
}