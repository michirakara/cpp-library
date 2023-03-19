---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: union-find/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/union-find.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 4 \"union-find/union-find.hpp\"\nstruct UnionFind{\n\
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
    \        }\n        return ret;\n    }\n};\n#line 7 \"verify/yosupo/union-find.test.cpp\"\
    \n\nint main(){\n    int n,q;\n    cin>>n>>q;\n\n    UnionFind uf(n);\n    \n\
    \    for(int _i=0;_i<q;_i++){\n        int t,u,v;\n        cin>>t>>u>>v;\n   \
    \     if(t==0){\n            uf.unite(u,v);\n        }else{\n            cout<<(uf.same(u,v)?1:0)<<endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../union-find/union-find.hpp\"\
    \n\nint main(){\n    int n,q;\n    cin>>n>>q;\n\n    UnionFind uf(n);\n    \n\
    \    for(int _i=0;_i<q;_i++){\n        int t,u,v;\n        cin>>t>>u>>v;\n   \
    \     if(t==0){\n            uf.unite(u,v);\n        }else{\n            cout<<(uf.same(u,v)?1:0)<<endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - union-find/union-find.hpp
  isVerificationFile: true
  path: verify/yosupo/union-find.test.cpp
  requiredBy: []
  timestamp: '2023-03-19 13:07:39-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/union-find.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/union-find.test.cpp
- /verify/verify/yosupo/union-find.test.cpp.html
title: verify/yosupo/union-find.test.cpp
---
