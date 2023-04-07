---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: segment-tree/segment-tree.hpp
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
    \    }\n    return ret;\n};\n#line 3 \"segment-tree/segment-tree.hpp\"\ntemplate\
    \ <class T,T(*op)(T,T),T(*e)()>\nstruct SegmentTree{\n    int n;\n    std::vector<T>\
    \ tree;\n    \n    SegmentTree(int n,std::vector<T> l={}){\n        //SegmentTree<T,op,e>(n,l={})\n\
    \        SegmentTree::n=(bits_msb(n))<<1;\n        tree.resize(SegmentTree::n*2,e());\n\
    \        for(int i=0;i<(int)l.size();i++)tree[SegmentTree::n+i]=l[i];\n      \
    \  for(int i=SegmentTree::n-1;i>0;i--)tree[i]=op(tree[i<<1],tree[(i<<1)+1]);\n\
    \    }\n\n    T at(int ind){\n        //O(1)\u3067\u30E9\u30F3\u30C0\u30E0\u30A2\
    \u30AF\u30BB\u30B9\n        return tree.at(n+ind);\n    }\n\n    T operator[](int\
    \ pos){\n        return tree[n+pos];\n    }\n\n    void set(int ind,T x){\n  \
    \      //O(log N)\u3067t[ind]\u3092x\u306B\u3059\u308B\n        ind+=n;\n    \
    \    tree[ind]=x;\n        while(ind>1){\n            tree[ind>>1]=op(tree[ind],tree[ind^1]);\n\
    \            ind>>=1;\n        }\n    }\n\n    T prod(int l, int r){\n       \
    \ //O(log N)\u3067t[l:r)\u306E\u30AF\u30A8\u30EA\n        T ret=e();\n       \
    \ l+=n;\n        r+=n;\n        while(l<r){\n            if(l&1){\n          \
    \      ret=op(ret,tree[l]);l++;\n            }\n            if(r&1){\n       \
    \         ret=op(ret,tree[r-1]);\n            }\n            r>>=1;\n        \
    \    l>>=1;\n        }\n        return ret;\n    }\n\nprivate:\n    unsigned int\
    \ bits_msb( unsigned int v ){\n    v = v | (v >>  1);\n    v = v | (v >>  2);\n\
    \    v = v | (v >>  4);\n    v = v | (v >>  8);\n    v = v | (v >> 16);\n    return\
    \ v ^ (v >> 1);\n    }\n};\n#line 3 \"tree/heavy-light-decomposition.hpp\"\n\n\
    #line 7 \"tree/heavy-light-decomposition.hpp\"\n\ntemplate<class S,S(*op)(S,S),S(*e)()>\n\
    struct HeavyLightDecomposition{\n    UnweightedGraph T;\n    SegmentTree<S,op,e>\
    \ sg;\n    int N;\n    std::vector<int> parent,siz_t,depth,shallow,hld,rev_hld;\n\
    \    int dfs(int now,int prev){\n        parent[now]=prev;\n        depth[now]=prev!=-1?depth[prev]+1:0;\n\
    \        int siz=1;\n        for(int i:T[now]){\n            if(i==prev)continue;\n\
    \            siz+=dfs(i,now);\n        }\n        siz_t[now]=siz;\n        return\
    \ siz;\n    }\n    void dfs2(int now,int prev,bool new_path){\n        rev_hld[now]=hld.size();\n\
    \        hld.push_back(now);\n        shallow[now]=new_path?now:shallow[prev];\n\
    \n        int ma=0,ma_idx=-1;\n        for(int i:T[now]){\n            if(i!=prev\
    \ && siz_t[i]>ma){\n                ma=siz_t[i],ma_idx=i;\n            }\n   \
    \     }\n        if(ma_idx==-1)return;\n        dfs2(ma_idx,now,false);\n\n  \
    \      for(int i:T[now]){\n            if(i!=ma_idx && i!=prev)dfs2(i,now,true);\n\
    \        }\n    }\n    HeavyLightDecomposition(UnweightedGraph &T):T(T),sg(SegmentTree<S,op,e>(T.size())){\n\
    \        N=HeavyLightDecomposition::T.size();\n        parent.resize(N);\n   \
    \     siz_t.resize(N);\n        depth.resize(N);\n        shallow.resize(N);\n\
    \        rev_hld.resize(N);\n        dfs(0,-1);\n        dfs2(0,-1,1);\n    }\n\
    \n    std::vector<std::pair<int,int>> q(int u,int v){\n        std::vector<std::pair<int,int>>\
    \ ret;\n        while(shallow[u]!=shallow[v]){\n            if(depth[shallow[u]]<=depth[shallow[v]]){\n\
    \                ret.push_back({rev_hld[shallow[v]],rev_hld[v]});\n          \
    \      v=parent[shallow[v]];\n            }else{\n                ret.push_back({rev_hld[shallow[u]],rev_hld[u]});\n\
    \                u=parent[shallow[u]];\n            }\n        }\n        ret.push_back({std::min(rev_hld[u],rev_hld[v]),std::max(rev_hld[u],rev_hld[v])});\n\
    \        return ret;\n    }\n\n    void set(int u,int v,S x){\n        if(parent[v]==u){\n\
    \            sg.set(rev_hld[v],x);\n        }else{\n            sg.set(rev_hld[u],x);\n\
    \        }\n    }\n\n    S query(int u,int v){\n        std::vector<std::pair<int,int>>\
    \ que=q(u,v);\n        S ret=e();\n        for(int i=0;i<que.size()-1;i++){\n\
    \            ret=op(ret,sg.prod(que[i].first,que[i].second+1));\n        }\n \
    \       if(que.back().first!=N-1 && que.back().first!=que.back().second){\n  \
    \          ret=op(ret,sg.prod(que.back().first+1,que.back().second+1));\n    \
    \    }\n        return ret;\n    }\n\n    int lcu(int u,int v){\n        return\
    \ hld[q(u,v).back().first];\n    }\n};\n#line 7 \"verify/yosupo/hld-lcu.test.cpp\"\
    \n\nusing S=long long;\nS op(S a,S b){return a+b;}\nS e(){return 0;}\nint main(){\n\
    \    int n,q;cin>>n>>q;\n    UnweightedGraph T(n);\n    for(int i=1;i<n;i++){\n\
    \        int tmp;cin>>tmp;\n        T[tmp].push_back(i);\n        T[i].push_back(tmp);\n\
    \    }\n    HeavyLightDecomposition<S,op,e> HLD(T);\n    while(q--){\n       \
    \ int u,v;cin>>u>>v;\n        cout<<HLD.lcu(u,v)<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../tree/heavy-light-decomposition.hpp\"\n\
    \nusing S=long long;\nS op(S a,S b){return a+b;}\nS e(){return 0;}\nint main(){\n\
    \    int n,q;cin>>n>>q;\n    UnweightedGraph T(n);\n    for(int i=1;i<n;i++){\n\
    \        int tmp;cin>>tmp;\n        T[tmp].push_back(i);\n        T[i].push_back(tmp);\n\
    \    }\n    HeavyLightDecomposition<S,op,e> HLD(T);\n    while(q--){\n       \
    \ int u,v;cin>>u>>v;\n        cout<<HLD.lcu(u,v)<<endl;\n    }\n}"
  dependsOn:
  - tree/heavy-light-decomposition.hpp
  - graph/graph-template.hpp
  - segment-tree/segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/hld-lcu.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 21:49:44-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/hld-lcu.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/hld-lcu.test.cpp
- /verify/verify/yosupo/hld-lcu.test.cpp.html
title: verify/yosupo/hld-lcu.test.cpp
---
