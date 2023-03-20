---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/binary-indexed-tree.test.cpp
    title: verify/aoj/binary-indexed-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment-tree/binary-indexed-tree.hpp\"\n#include<vector>\n\
    struct BinaryIndexedTree{\n    // 0-indexed\n    int size;\n    std::vector<long\
    \ long> tree={0};\n\n    BinaryIndexedTree(int n,std::vector<long long> l={}):size(n){\n\
    \        if(l.empty()){\n            for(int i=0;i<size;i++)tree.push_back(0);\n\
    \        }else{\n            for(long long i:l){\n                tree.push_back(i);\n\
    \            }\n            std::vector<long long> c(n+1,0);\n            for(int\
    \ i=0;i<size;i++){\n                c[i+1]=l[i]+c[i];\n            }\n       \
    \     for(int x=1;x<=size;x++){\n                tree[x]=c[x]-c[x-(x&-x)];\n \
    \           }\n        }\n    }\n\n    long long _sum(int r){\n        //sum(t[0,r))\n\
    \        if(r==0)return 0;\n        long long s=0;\n        while(r>0){\n    \
    \        s+=tree[r];\n            r-=r&-r;\n        }\n        return s;\n   \
    \ }\n\n    long long sum(int l,int r){\n        //sum(t[l,r))\n        return\
    \ _sum(r)-_sum(l);\n    }\n\n    void add(int i,long long x){\n        //t[i]+=x\n\
    \        i++;\n        while(i<=size){\n            tree[i]+=x;\n            i+=i&-i;\n\
    \        }\n    }\n};\n"
  code: "#include<vector>\nstruct BinaryIndexedTree{\n    // 0-indexed\n    int size;\n\
    \    std::vector<long long> tree={0};\n\n    BinaryIndexedTree(int n,std::vector<long\
    \ long> l={}):size(n){\n        if(l.empty()){\n            for(int i=0;i<size;i++)tree.push_back(0);\n\
    \        }else{\n            for(long long i:l){\n                tree.push_back(i);\n\
    \            }\n            std::vector<long long> c(n+1,0);\n            for(int\
    \ i=0;i<size;i++){\n                c[i+1]=l[i]+c[i];\n            }\n       \
    \     for(int x=1;x<=size;x++){\n                tree[x]=c[x]-c[x-(x&-x)];\n \
    \           }\n        }\n    }\n\n    long long _sum(int r){\n        //sum(t[0,r))\n\
    \        if(r==0)return 0;\n        long long s=0;\n        while(r>0){\n    \
    \        s+=tree[r];\n            r-=r&-r;\n        }\n        return s;\n   \
    \ }\n\n    long long sum(int l,int r){\n        //sum(t[l,r))\n        return\
    \ _sum(r)-_sum(l);\n    }\n\n    void add(int i,long long x){\n        //t[i]+=x\n\
    \        i++;\n        while(i<=size){\n            tree[i]+=x;\n            i+=i&-i;\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2023-02-18 21:45:20-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/binary-indexed-tree.test.cpp
documentation_of: segment-tree/binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/binary-indexed-tree.hpp
- /library/segment-tree/binary-indexed-tree.hpp.html
title: segment-tree/binary-indexed-tree.hpp
---
