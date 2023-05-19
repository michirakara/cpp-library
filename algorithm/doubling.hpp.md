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
  bundledCode: "#line 1 \"algorithm/doubling.hpp\"\n#include<vector>\nstruct Doubling{\n\
    \    std::vector<std::vector<int>> dp;\n    Doubling(std::vector<int> next){\n\
    \        dp.resize(64);\n        for(int i=0;i<64;i++){\n            dp[i].resize((int)next.size());\n\
    \        }\n        for(int i=0;i<(int)next.size();i++){\n            dp[0][i]=next[i];\n\
    \        }\n\n        for(int i=0;i<63;i++){\n            for(int j=0;j<(int)next.size();j++){\n\
    \                dp[i+1][j]=dp[i][dp[i][j]];\n            }\n        }\n    }\n\
    \n    int query(int start,long long turn){\n        int res=start;\n        for(int\
    \ i=0;i<64;i++){\n            if(turn&(1ll<<(long long)i)){\n                res=dp[i][res];\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  code: "#include<vector>\nstruct Doubling{\n    std::vector<std::vector<int>> dp;\n\
    \    Doubling(std::vector<int> next){\n        dp.resize(64);\n        for(int\
    \ i=0;i<64;i++){\n            dp[i].resize((int)next.size());\n        }\n   \
    \     for(int i=0;i<(int)next.size();i++){\n            dp[0][i]=next[i];\n  \
    \      }\n\n        for(int i=0;i<63;i++){\n            for(int j=0;j<(int)next.size();j++){\n\
    \                dp[i+1][j]=dp[i][dp[i][j]];\n            }\n        }\n    }\n\
    \n    int query(int start,long long turn){\n        int res=start;\n        for(int\
    \ i=0;i<64;i++){\n            if(turn&(1ll<<(long long)i)){\n                res=dp[i][res];\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/doubling.hpp
  requiredBy: []
  timestamp: '2023-05-18 19:34:51-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/doubling.hpp
layout: document
redirect_from:
- /library/algorithm/doubling.hpp
- /library/algorithm/doubling.hpp.html
title: algorithm/doubling.hpp
---
