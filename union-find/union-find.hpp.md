---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/union-find.test.cpp
    title: verify/yosupo/union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"union-find/union-find.hpp\"\n#include<iostream>\n#include<vector>\n\
    #include<unordered_map>\nstruct UnionFind{\n    int n;\n    std::vector<int> par;\n\
    \    int group_cnt;\n    \n    //\u8981\u7D20\u6570N\u306EUnionFind\u3092\u4F5C\
    \u6210\n    UnionFind(int n):par(n,-1),group_cnt(n),n(n){}\n\n    //x\u306E\u89AA\
    \u3092\u63A2\u3059\n    int find(int x){\n        if(par.at(x)<0){\n         \
    \   return x;\n        }else{\n            par.at(x)=find(par.at(x));\n      \
    \      return par.at(x);\n        }\n    }\n\n    //x\u3068y\u3092\u9023\u7D50\
    \n    void unite(int x,int y){\n        x=find(x),y=find(y);\n        if(x==y)return;\n\
    \        if(par.at(x)>par.at(y))std::swap(x,y);\n        par.at(x)+=par.at(y);\n\
    \        par.at(y)=x;\n        group_cnt--;\n        return;\n    }\n\n    int\
    \ size(int x){\n        return -par.at(find(x));\n    }\n\n    bool same(int x,int\
    \ y){\n        return find(x)==find(y);\n    }\n\n    std::vector<int> members(int\
    \ x){\n        int root=find(x);\n        std::vector<int> ret;\n        for(int\
    \ i=0;i<n;i++){\n            if(find(i)==root)ret.push_back(i);\n        }\n \
    \       return ret;\n    }\n\n    std::vector<int> roots(){\n        std::vector<int>\
    \ ret;\n        for(int i=0;i<n;i++){\n            if(par.at(i)<0)ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    int grp_cnt(){\n        return group_cnt;\n\
    \    }\n\n    std::unordered_map<int,std::vector<int>> grp_mem(){\n        std::unordered_map<int,std::vector<int>>\
    \ ret;\n        for(int i=0;i<n;i++){\n            ret[find(i)].push_back(i);\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#include<iostream>\n#include<vector>\n#include<unordered_map>\nstruct UnionFind{\n\
    \    int n;\n    std::vector<int> par;\n    int group_cnt;\n    \n    //\u8981\
    \u7D20\u6570N\u306EUnionFind\u3092\u4F5C\u6210\n    UnionFind(int n):par(n,-1),group_cnt(n),n(n){}\n\
    \n    //x\u306E\u89AA\u3092\u63A2\u3059\n    int find(int x){\n        if(par.at(x)<0){\n\
    \            return x;\n        }else{\n            par.at(x)=find(par.at(x));\n\
    \            return par.at(x);\n        }\n    }\n\n    //x\u3068y\u3092\u9023\
    \u7D50\n    void unite(int x,int y){\n        x=find(x),y=find(y);\n        if(x==y)return;\n\
    \        if(par.at(x)>par.at(y))std::swap(x,y);\n        par.at(x)+=par.at(y);\n\
    \        par.at(y)=x;\n        group_cnt--;\n        return;\n    }\n\n    int\
    \ size(int x){\n        return -par.at(find(x));\n    }\n\n    bool same(int x,int\
    \ y){\n        return find(x)==find(y);\n    }\n\n    std::vector<int> members(int\
    \ x){\n        int root=find(x);\n        std::vector<int> ret;\n        for(int\
    \ i=0;i<n;i++){\n            if(find(i)==root)ret.push_back(i);\n        }\n \
    \       return ret;\n    }\n\n    std::vector<int> roots(){\n        std::vector<int>\
    \ ret;\n        for(int i=0;i<n;i++){\n            if(par.at(i)<0)ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    int grp_cnt(){\n        return group_cnt;\n\
    \    }\n\n    std::unordered_map<int,std::vector<int>> grp_mem(){\n        std::unordered_map<int,std::vector<int>>\
    \ ret;\n        for(int i=0;i<n;i++){\n            ret[find(i)].push_back(i);\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: union-find/union-find.hpp
  requiredBy: []
  timestamp: '2023-02-22 09:23:56-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/union-find.test.cpp
documentation_of: union-find/union-find.hpp
layout: document
title: Union Find
---

# 概要
素集合データ構造です  
詳しくはググってください

# 例
- __UnionFind(int N)__ := N頂点のUniFを作る $O(N)$
- __int find(int x)__ := 頂点xの親を探す $O(α)$
- __void unite(int x, int y)__ := 頂点xと頂点yを辺でつなげる $O(α)$
- __int size(int x)__ := 頂点xが属する木のサイズを返す $O(α)$
- __bool same(int x, int y)__ := 頂点xと頂点yが同じ木に含まれているか判定する $O(α)$
- __vector\<int\> members(int x)__ := 頂点xと同じ木に含まれている頂点を全て返す $O(αN)$
- __vector\<int\> roots()__ := 親を全て返す $O(αN)$
- __int grp_cnt()__ := 木の数を返す $O(1)$
- __unordered_map\<int,vector\<int\>\> grp_mem()__ := 親をkey、その木に含まれているすべての頂点のリストをvalueとしたunordered_mapを返す $O(αN)$
