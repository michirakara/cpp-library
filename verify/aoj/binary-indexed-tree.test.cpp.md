---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/binary-indexed-tree.hpp
    title: segment-tree/binary-indexed-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/aoj/binary-indexed-tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"segment-tree/binary-indexed-tree.hpp\"\
    \nstruct BinaryIndexedTree{\n    // 0-indexed\n    int size;\n    std::vector<long\
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
    \        }\n    }\n};\n#line 7 \"verify/aoj/binary-indexed-tree.test.cpp\"\n\n\
    int main(){\n    int N,Q;cin>>N>>Q;\n    BinaryIndexedTree bit(N);\n\n    while(Q--){\n\
    \        int com,x,y;cin>>com>>x>>y;\n\n        if(com==0)bit.add(x-1,y);\n  \
    \      else cout<<bit.sum(x-1,y)<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../segment-tree/binary-indexed-tree.hpp\"\
    \n\nint main(){\n    int N,Q;cin>>N>>Q;\n    BinaryIndexedTree bit(N);\n\n   \
    \ while(Q--){\n        int com,x,y;cin>>com>>x>>y;\n\n        if(com==0)bit.add(x-1,y);\n\
    \        else cout<<bit.sum(x-1,y)<<endl;\n    }\n}"
  dependsOn:
  - segment-tree/binary-indexed-tree.hpp
  isVerificationFile: true
  path: verify/aoj/binary-indexed-tree.test.cpp
  requiredBy: []
  timestamp: '2023-03-19 23:21:06-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/binary-indexed-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/binary-indexed-tree.test.cpp
- /verify/verify/aoj/binary-indexed-tree.test.cpp.html
title: verify/aoj/binary-indexed-tree.test.cpp
---
