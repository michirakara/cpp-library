---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: tree/heavy-light-decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/yosupo/hld-lcu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    \    }\n    return ret;\n};\n#line 2 \"tree/heavy-light-decomposition.hpp\"\n\n\
    #line 7 \"tree/heavy-light-decomposition.hpp\"\n\ntemplate<class S>\nstruct HeavyLightDecomposition{\n\
    \    UnweightedGraph T;\n    int N;\n    std::vector<int> parent,siz_t,depth,shallow,hld,rev_hld;\n\
    \    int dfs(int now,int prev){\n        parent[now]=prev;\n        depth[now]=prev!=-1?depth[prev]+1:0;\n\
    \        int siz=1;\n        for(int i:T[now]){\n            if(i==prev)continue;\n\
    \            siz+=dfs(i,now);\n        }\n        siz_t[now]=siz;\n        return\
    \ siz;\n    }\n    void dfs2(int now,int prev,bool new_path){\n        rev_hld[now]=hld.size();\n\
    \        hld.push_back(now);\n        shallow[now]=new_path?now:shallow[prev];\n\
    \n        int ma=0,ma_idx=-1;\n        for(int i:T[now]){\n            if(i!=prev\
    \ && siz_t[i]>ma){\n                ma=siz_t[i],ma_idx=i;\n            }\n   \
    \     }\n        if(ma_idx==-1)return;\n        dfs2(ma_idx,now,false);\n\n  \
    \      for(int i:T[now]){\n            if(i!=ma_idx && i!=prev)dfs2(i,now,true);\n\
    \        }\n    }\n    HeavyLightDecomposition(UnweightedGraph &T):T(T){\n   \
    \     N=HeavyLightDecomposition::T.size();\n        parent.resize(N);\n      \
    \  siz_t.resize(N);\n        depth.resize(N);\n        shallow.resize(N);\n  \
    \      rev_hld.resize(N);\n        dfs(0,-1);\n        dfs2(0,-1,1);\n    }\n\n\
    \    std::vector<std::pair<int,int>> q(int u,int v){\n        std::vector<std::pair<int,int>>\
    \ ret;\n        while(shallow[u]!=shallow[v]){\n            if(depth[shallow[u]]<=depth[shallow[v]]){\n\
    \                ret.push_back({rev_hld[shallow[v]],rev_hld[v]});\n          \
    \      v=parent[shallow[v]];\n            }else{\n                ret.push_back({rev_hld[shallow[u]],rev_hld[u]});\n\
    \                u=parent[shallow[u]];\n            }\n        }\n        ret.push_back({std::min(rev_hld[u],rev_hld[v]),std::max(rev_hld[u],rev_hld[v])});\n\
    \        return ret;\n    }\n\n    void set(int u,int v,S x,std::function<void(int,int)>\
    \ f){\n        if(parent[v]==u){\n            f(rev_hld[v],x);\n        }else{\n\
    \            f(rev_hld[u],x);\n        }\n    }\n\n    S query(int u,int v,S id,std::function<S(int,int)>\
    \ f,std::function<S(S,S)> op){\n        std::vector<std::pair<int,int>> que=q(u,v);\n\
    \        S ret=id;\n        for(int i=0;i<que.size()-1;i++){\n            ret=op(ret,f(que[i].first,que[i].second+1));\n\
    \        }\n        if(que.back().first!=N-1 && que.back().first!=que.back().second){\n\
    \            ret=op(ret,f(que.back().first+1,que.back().second+1));\n        }\n\
    \        return ret;\n    }\n\n    int lcu(int u,int v){\n        return hld[q(u,v).back().first];\n\
    \    }\n};\n#line 7 \"verify/yosupo/hld-lcu.test.cpp\"\n\nusing S=long long;\n\
    S op(S a,S b){return a+b;}\nS e(){return 0;}\nint main(){\n    int n,q;cin>>n>>q;\n\
    \    UnweightedGraph T(n);\n    for(int i=1;i<n;i++){\n        int tmp;cin>>tmp;\n\
    \        T[tmp].push_back(i);\n        T[i].push_back(tmp);\n    }\n    HeavyLightDecomposition<S>\
    \ HLD(T);\n    while(q--){\n        int u,v;cin>>u>>v;\n        cout<<HLD.lcu(u,v)<<endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../tree/heavy-light-decomposition.hpp\"\n\
    \nusing S=long long;\nS op(S a,S b){return a+b;}\nS e(){return 0;}\nint main(){\n\
    \    int n,q;cin>>n>>q;\n    UnweightedGraph T(n);\n    for(int i=1;i<n;i++){\n\
    \        int tmp;cin>>tmp;\n        T[tmp].push_back(i);\n        T[i].push_back(tmp);\n\
    \    }\n    HeavyLightDecomposition<S> HLD(T);\n    while(q--){\n        int u,v;cin>>u>>v;\n\
    \        cout<<HLD.lcu(u,v)<<endl;\n    }\n}"
  dependsOn:
  - tree/heavy-light-decomposition.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/yosupo/hld-lcu.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 06:06:13-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/hld-lcu.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/hld-lcu.test.cpp
- /verify/verify/yosupo/hld-lcu.test.cpp.html
title: verify/yosupo/hld-lcu.test.cpp
---
