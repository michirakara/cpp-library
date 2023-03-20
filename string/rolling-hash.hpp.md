---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/rolling-hash.test.cpp
    title: verify/aoj/rolling-hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\n#include<iostream>\n#include<vector>\n\
    using ull=unsigned long long;\nstruct RollingHash{\n    ull MOD=(1ull<<61)-1,MASK31=(1ull<<31)-1,MASK30=(1ull<<30)-1;\n\
    \    ull base;\n    std::vector<ull> li={0},p={1};\n\n    ull _mod(ull x){\n \
    \       ull xu=x>>61,xd=x&MOD;\n        ull res=xu+xd;\n        if(res>=MOD)res-=MOD;\n\
    \        return res;\n    }\n\n    ull _mul(ull a,ull b){\n        ull au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;\n\
    \        ull mid=ad*bu+au*bd;\n        ull midu=mid>>30;\n        ull midd=mid&MASK30;\n\
    \        return _mod(au*bu*2+midu+(midd<<31)+ad*bd);\n    }\n\n    RollingHash(std::string\
    \ s,int base){\n        RollingHash::base=base;\n        for(int i=1;i<=s.size();i++){\n\
    \            p.push_back(_mul(p[i-1],base));\n            li.push_back((_mul(li[i-1],base)+s[i-1])%MOD);\n\
    \        }\n    }\n\n    ull hash(int l,int r){\n        //[l,r)\n        return\
    \ (MOD+li[r]-_mul(li[l],p[r-l]))%MOD;\n    }\n};\n"
  code: "#include<iostream>\n#include<vector>\nusing ull=unsigned long long;\nstruct\
    \ RollingHash{\n    ull MOD=(1ull<<61)-1,MASK31=(1ull<<31)-1,MASK30=(1ull<<30)-1;\n\
    \    ull base;\n    std::vector<ull> li={0},p={1};\n\n    ull _mod(ull x){\n \
    \       ull xu=x>>61,xd=x&MOD;\n        ull res=xu+xd;\n        if(res>=MOD)res-=MOD;\n\
    \        return res;\n    }\n\n    ull _mul(ull a,ull b){\n        ull au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;\n\
    \        ull mid=ad*bu+au*bd;\n        ull midu=mid>>30;\n        ull midd=mid&MASK30;\n\
    \        return _mod(au*bu*2+midu+(midd<<31)+ad*bd);\n    }\n\n    RollingHash(std::string\
    \ s,int base){\n        RollingHash::base=base;\n        for(int i=1;i<=s.size();i++){\n\
    \            p.push_back(_mul(p[i-1],base));\n            li.push_back((_mul(li[i-1],base)+s[i-1])%MOD);\n\
    \        }\n    }\n\n    ull hash(int l,int r){\n        //[l,r)\n        return\
    \ (MOD+li[r]-_mul(li[l],p[r-l]))%MOD;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-02-15 18:07:32-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/rolling-hash.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
