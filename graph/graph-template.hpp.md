---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':x:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dijkstra.test.cpp
    title: verify/aoj/dijkstra.test.cpp
  - icon: ':x:'
    path: verify/aoj/scc.test.cpp
    title: verify/aoj/scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph-template.hpp\"\n#include <iostream>\n#include\
    \ <vector>\ntemplate<class T>\nstruct edge{\n    int from,to;\n    T cost;\n \
    \   \n    edge(int to,T cost):from(-1),to(to),cost(cost){}\n    edge(int from,int\
    \ to,T cost):from(from),to(to),cost(cost){}\n\n    edge &operator=(const int &x){\n\
    \        to=x;\n        return *this;\n    }\n};\n\ntemplate<class T>\nusing Edges\
    \ = std::vector<edge<T>>;\n\ntemplate<class T>\nusing WeightedGraph = std::vector<Edges<T>>;\n\
    using UnweightedGraph = std::vector<std::vector<int>>;\n\nUnweightedGraph input_graph(int\
    \ N,int M,bool directed=false,bool one_origin=true){\n    UnweightedGraph ret(N);\n\
    \    for(int i=0;i<M;i++){\n        int from,to;std::cin>>from>>to;\n        if(one_origin)from--,to--;\n\
    \        ret[from].push_back(to);\n        if(!directed)ret[to].push_back(from);\n\
    \    }\n    return ret;\n};\n\ntemplate<class T>\nWeightedGraph<T> input_wgraph(int\
    \ N,int M,bool directed=false,bool one_origin=true){\n    WeightedGraph<T> ret(N);\n\
    \    for(int i=0;i<M;i++){\n        int from,to;T cost;std::cin>>from>>to>>cost;\n\
    \        if(one_origin)from--,to--;\n        ret[from].emplace_back(from,to,cost);\n\
    \        if(!directed)ret[to].emplace_back(to,from,cost);\n    }\n    return ret;\n\
    };\n"
  code: "#include <iostream>\n#include <vector>\ntemplate<class T>\nstruct edge{\n\
    \    int from,to;\n    T cost;\n    \n    edge(int to,T cost):from(-1),to(to),cost(cost){}\n\
    \    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n\n    edge &operator=(const\
    \ int &x){\n        to=x;\n        return *this;\n    }\n};\n\ntemplate<class\
    \ T>\nusing Edges = std::vector<edge<T>>;\n\ntemplate<class T>\nusing WeightedGraph\
    \ = std::vector<Edges<T>>;\nusing UnweightedGraph = std::vector<std::vector<int>>;\n\
    \nUnweightedGraph input_graph(int N,int M,bool directed=false,bool one_origin=true){\n\
    \    UnweightedGraph ret(N);\n    for(int i=0;i<M;i++){\n        int from,to;std::cin>>from>>to;\n\
    \        if(one_origin)from--,to--;\n        ret[from].push_back(to);\n      \
    \  if(!directed)ret[to].push_back(from);\n    }\n    return ret;\n};\n\ntemplate<class\
    \ T>\nWeightedGraph<T> input_wgraph(int N,int M,bool directed=false,bool one_origin=true){\n\
    \    WeightedGraph<T> ret(N);\n    for(int i=0;i<M;i++){\n        int from,to;T\
    \ cost;std::cin>>from>>to>>cost;\n        if(one_origin)from--,to--;\n       \
    \ ret[from].emplace_back(from,to,cost);\n        if(!directed)ret[to].emplace_back(to,from,cost);\n\
    \    }\n    return ret;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph-template.hpp
  requiredBy:
  - graph/dijkstra.hpp
  - graph/scc.hpp
  timestamp: '2023-03-24 23:12:28-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/scc.test.cpp
  - verify/aoj/dijkstra.test.cpp
documentation_of: graph/graph-template.hpp
layout: document
redirect_from:
- /library/graph/graph-template.hpp
- /library/graph/graph-template.hpp.html
title: graph/graph-template.hpp
---