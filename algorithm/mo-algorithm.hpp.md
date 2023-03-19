---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/mo-algorithm.hpp\"\n#include<vector>\n#include<utility>\n\
    #include<numeric>\n#include<algorithm>\nstruct Mo{\n    int n;\n    std::vector<std::pair<int,int>>\
    \ lr;\n    explicit Mo(int n):n(n){}\n\n    void add(int l,int r){/*[l,r)*/\n\
    \        lr.emplace_back(l,r);\n    }\n\n    template<typename AL,typename AR,typename\
    \ EL,typename ER,typename O>\n    void build(const AL &add_left,const AR &add_right,const\
    \ EL &erase_left,const ER &erase_right,const O &out){\n        int q=lr.size();\n\
    \        int width=n/min<int>(n,sqrt(q));\n        std::vector<int> order(q);\n\
    \        std::iota(order.begin(),order.end(),0);\n        std::sort(order.begin(),order.end(),[&](int\
    \ a,int b){\n            int a_block=lr[a].first/width,b_block=lr[b].first/width;\n\
    \            if(a_block!=b_block)return a_block<b_block;\n            return a_block%2==0\
    \ ? lr[a].second<lr[b].second : lr[a].second>lr[b].second;\n        });\n\n  \
    \      int l=0,r=0;\n        for(auto i:order){\n            while(l>lr[i].first)add_left(--l);\n\
    \            while(r<lr[i].second)add_right(r++);\n            while(l<lr[i].first)erase_left(l++);\n\
    \            while(r>lr[i].second)erase_right(--r);\n            out(i);\n   \
    \     }\n    }\n    template<typename A,typename E,typename O>\n    void build(const\
    \ A &add,const E & erase,const O &out){\n        build(add,add,erase,erase,out);\n\
    \    }\n};\n"
  code: "#include<vector>\n#include<utility>\n#include<numeric>\n#include<algorithm>\n\
    struct Mo{\n    int n;\n    std::vector<std::pair<int,int>> lr;\n    explicit\
    \ Mo(int n):n(n){}\n\n    void add(int l,int r){/*[l,r)*/\n        lr.emplace_back(l,r);\n\
    \    }\n\n    template<typename AL,typename AR,typename EL,typename ER,typename\
    \ O>\n    void build(const AL &add_left,const AR &add_right,const EL &erase_left,const\
    \ ER &erase_right,const O &out){\n        int q=lr.size();\n        int width=n/min<int>(n,sqrt(q));\n\
    \        std::vector<int> order(q);\n        std::iota(order.begin(),order.end(),0);\n\
    \        std::sort(order.begin(),order.end(),[&](int a,int b){\n            int\
    \ a_block=lr[a].first/width,b_block=lr[b].first/width;\n            if(a_block!=b_block)return\
    \ a_block<b_block;\n            return a_block%2==0 ? lr[a].second<lr[b].second\
    \ : lr[a].second>lr[b].second;\n        });\n\n        int l=0,r=0;\n        for(auto\
    \ i:order){\n            while(l>lr[i].first)add_left(--l);\n            while(r<lr[i].second)add_right(r++);\n\
    \            while(l<lr[i].first)erase_left(l++);\n            while(r>lr[i].second)erase_right(--r);\n\
    \            out(i);\n        }\n    }\n    template<typename A,typename E,typename\
    \ O>\n    void build(const A &add,const E & erase,const O &out){\n        build(add,add,erase,erase,out);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/mo-algorithm.hpp
  requiredBy: []
  timestamp: '2023-03-13 17:08:45-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/mo-algorithm.hpp
layout: document
redirect_from:
- /library/algorithm/mo-algorithm.hpp
- /library/algorithm/mo-algorithm.hpp.html
title: algorithm/mo-algorithm.hpp
---
