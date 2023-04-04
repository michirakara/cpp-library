---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':x:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/aoj/scc.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
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
    \    }\n    return ret;\n};\n#line 2 \"graph/scc.hpp\"\n\n#line 5 \"graph/scc.hpp\"\
    \nstruct SCC{\n    std::vector<int> where;\n\n    std::vector<UnweightedGraph>\
    \ build(UnweightedGraph &G){\n        UnweightedGraph rev_graph((int)G.size());\n\
    \        std::vector<int> order;\n\n        {std::vector<bool> been((int)G.size(),false);\n\
    \        std::stack<int> st;\n        st.push(0);\n        while(!st.empty()){\n\
    \            int now=st.top();st.pop();\n            if(now>=0){\n           \
    \     been[now]=true;\n                for(int i:G[now]){\n                  \
    \  rev_graph[i].push_back(now);\n                    if(been[i])continue;\n  \
    \                  st.push(-i-1);\n                    st.push(i);\n         \
    \       }\n            }else{\n                now=-now-1;\n                order.push_back(now);\n\
    \            }\n        }}\n        std::reverse(order.begin(),order.end());\n\
    \        std::vector<UnweightedGraph> ret;\n        std::vector<int> index((int)G.size(),-1);\n\
    \        std::vector<int> been_2((int)G.size(),-1);\n        for(int start:order){\n\
    \            if(been_2[start]!=-1)continue;\n            std::stack<int> st={};\n\
    \            st.push(start);\n            index[start]=0;\n            ret.push_back({{}});\n\
    \            while(!st.empty()){\n                int now=st.top();st.pop();\n\
    \                been_2[now]=start;\n                for(int i:rev_graph[now]){\n\
    \                    if(been_2[i]!=start && been_2[i]!=-1)continue;\n        \
    \            if(index[i]==-1){\n                        index[i]=(int)ret.back().size();\n\
    \                        ret.back().push_back({});\n                    }\n  \
    \                  ret.back()[index[i]].push_back(now);\n                    if(been_2[i]==-1)st.push(i);\n\
    \                }\n            }\n        }\n        where=been_2;\n        return\
    \ ret;\n    }\n\n    int operator[](int v){\n        return where[v];\n    }\n\
    };\n#line 7 \"verify/aoj/scc.test.cpp\"\n\nint main(){\n    int V,E;\n    cin>>V>>E;\n\
    \    UnweightedGraph G=input_graph(V,E,true,false);\n    SCC scc;scc.build(G);\n\
    \    int Q;\n    cin>>Q;\n    while(Q--){\n        int u,v;\n        cin>>u>>v;\n\
    \        cout<<(scc[u]==scc[v]?1:0)<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/scc.hpp\"\
    \n\nint main(){\n    int V,E;\n    cin>>V>>E;\n    UnweightedGraph G=input_graph(V,E,true,false);\n\
    \    SCC scc;scc.build(G);\n    int Q;\n    cin>>Q;\n    while(Q--){\n       \
    \ int u,v;\n        cin>>u>>v;\n        cout<<(scc[u]==scc[v]?1:0)<<endl;\n  \
    \  }\n}"
  dependsOn:
  - graph/scc.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/aoj/scc.test.cpp
  requiredBy: []
  timestamp: '2023-04-03 22:07:37-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/scc.test.cpp
- /verify/verify/aoj/scc.test.cpp.html
title: verify/aoj/scc.test.cpp
---
