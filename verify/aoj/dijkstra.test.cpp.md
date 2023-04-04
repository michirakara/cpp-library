---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/aoj/dijkstra.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\
    \ntemplate<class T>\nstruct edge{\n    int from,to;\n    T cost;\n    \n    edge(int\
    \ to,T cost):from(-1),to(to),cost(cost){}\n    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n\
    \n    edge &operator=(const int &x){\n        to=x;\n        return *this;\n \
    \   }\n};\n\ntemplate<class T>\nusing Edges = std::vector<edge<T>>;\n\ntemplate<class\
    \ T>\nusing WeightedGraph = std::vector<Edges<T>>;\nusing UnweightedGraph = std::vector<std::vector<int>>;\n\
    \nUnweightedGraph input_graph(int N,int M,bool directed=false,bool one_origin=true){\n\
    \    UnweightedGraph ret(N);\n    for(int i=0;i<M;i++){\n        int from,to;std::cin>>from>>to;\n\
    \        if(one_origin)from--,to--;\n        ret[from].push_back(to);\n      \
    \  if(!directed)ret[to].push_back(from);\n    }\n    return ret;\n};\n\ntemplate<class\
    \ T>\nWeightedGraph<T> input_wgraph(int N,int M,bool directed=false,bool one_origin=true){\n\
    \    WeightedGraph<T> ret(N);\n    for(int i=0;i<M;i++){\n        int from,to;T\
    \ cost;std::cin>>from>>to>>cost;\n        if(one_origin)from--,to--;\n       \
    \ ret[from].emplace_back(from,to,cost);\n        if(!directed)ret[to].emplace_back(to,from,cost);\n\
    \    }\n    return ret;\n};\n#line 2 \"graph/dijkstra.hpp\"\n\n#line 6 \"graph/dijkstra.hpp\"\
    \n\ntemplate<class T>\nstd::vector<T> dijkstra(WeightedGraph<T> &graph,int start=0){\n\
    \    int n=(int)graph.size();\n    std::vector<T> dist(n,(T)-1);\n    std::vector<bool>\
    \ ok(n,false);\n\n    std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<std::pair<T,int>>>\
    \ Q;\n    dist[start]=0;\n    Q.push({dist[start],start});\n\n    while(!Q.empty()){\n\
    \        int pos=Q.top().second;Q.pop();\n        if(ok[pos])continue;\n     \
    \   ok[pos]=true;\n        for(int i=0;i<(int)graph[pos].size();i++){\n      \
    \      if(dist[graph[pos][i].to]==-1 || dist[graph[pos][i].to]>dist[pos]+graph[pos][i].cost){\n\
    \                dist[graph[pos][i].to]=dist[pos]+graph[pos][i].cost;\n      \
    \          Q.push({dist[graph[pos][i].to],graph[pos][i].to});\n            }\n\
    \        }\n    }\n\n    return dist;\n}\n#line 7 \"verify/aoj/dijkstra.test.cpp\"\
    \n\nint main(){\n    int V,E,r;\n    cin>>V>>E>>r;\n    WeightedGraph<int> g=input_wgraph<int>(V,E,true,false);\n\
    \    vector<int> ans=dijkstra<int>(g,r);\n\n    for(int i=0;i<V;i++){\n      \
    \  if(ans[i]==-1){\n            cout<<\"INF\"<<endl;\n        }else{\n       \
    \     cout<<ans[i]<<endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/dijkstra.hpp\"\
    \n\nint main(){\n    int V,E,r;\n    cin>>V>>E>>r;\n    WeightedGraph<int> g=input_wgraph<int>(V,E,true,false);\n\
    \    vector<int> ans=dijkstra<int>(g,r);\n\n    for(int i=0;i<V;i++){\n      \
    \  if(ans[i]==-1){\n            cout<<\"INF\"<<endl;\n        }else{\n       \
    \     cout<<ans[i]<<endl;\n        }\n    }\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/aoj/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-03-24 23:12:28-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/dijkstra.test.cpp
- /verify/verify/aoj/dijkstra.test.cpp.html
title: verify/aoj/dijkstra.test.cpp
---