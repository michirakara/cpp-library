---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: string/rolling-hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verify/aoj/rolling-hash.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"string/rolling-hash.hpp\"\
    \nusing ull=unsigned long long;\nstruct RollingHash{\n    ull MOD=(1ull<<61)-1,MASK31=(1ull<<31)-1,MASK30=(1ull<<30)-1;\n\
    \    ull base;\n    std::vector<ull> li={0},p={1};\n\n    ull _mod(ull x){\n \
    \       ull xu=x>>61,xd=x&MOD;\n        ull res=xu+xd;\n        if(res>=MOD)res-=MOD;\n\
    \        return res;\n    }\n\n    ull _mul(ull a,ull b){\n        ull au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;\n\
    \        ull mid=ad*bu+au*bd;\n        ull midu=mid>>30;\n        ull midd=mid&MASK30;\n\
    \        return _mod(au*bu*2+midu+(midd<<31)+ad*bd);\n    }\n\n    RollingHash(std::string\
    \ s,int base){\n        RollingHash::base=base;\n        for(int i=1;i<=s.size();i++){\n\
    \            p.push_back(_mul(p[i-1],base));\n            li.push_back((_mul(li[i-1],base)+s[i-1])%MOD);\n\
    \        }\n    }\n\n    ull hash(int l,int r){\n        //[l,r)\n        return\
    \ (MOD+li[r]-_mul(li[l],p[r-l]))%MOD;\n    }\n};\n#line 7 \"verify/aoj/rolling-hash.test.cpp\"\
    \n\nint main(){\n    string T,P;cin>>T>>P;\n    int base=27+rand()%50;\n    RollingHash\
    \ t(T,base),p(P,base);\n    if(T.size()<P.size()){\n        exit(0);\n    }\n\
    \    for(int i=0;i<=T.size()-P.size();i++){\n        if(t.hash(i,i+P.size())==p.hash(0,P.size()))cout<<i<<endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/rolling-hash.hpp\"\
    \n\nint main(){\n    string T,P;cin>>T>>P;\n    int base=27+rand()%50;\n    RollingHash\
    \ t(T,base),p(P,base);\n    if(T.size()<P.size()){\n        exit(0);\n    }\n\
    \    for(int i=0;i<=T.size()-P.size();i++){\n        if(t.hash(i,i+P.size())==p.hash(0,P.size()))cout<<i<<endl;\n\
    \    }\n}"
  dependsOn:
  - string/rolling-hash.hpp
  isVerificationFile: true
  path: verify/aoj/rolling-hash.test.cpp
  requiredBy: []
  timestamp: '2023-03-19 23:02:56-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/rolling-hash.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/rolling-hash.test.cpp
- /verify/verify/aoj/rolling-hash.test.cpp.html
title: verify/aoj/rolling-hash.test.cpp
---
