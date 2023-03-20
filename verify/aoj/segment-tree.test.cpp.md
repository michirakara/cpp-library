---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: segment-tree/segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/aoj/segment-tree.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"segment-tree/segment-tree.hpp\"\
    \ntemplate <class T,T(*op)(T,T),T(*e)()>\nstruct SegmentTree{\n    int n;\n  \
    \  std::vector<T> tree;\n    \n    SegmentTree(int n,std::vector<T> l={}){\n \
    \       //SegmentTree<T,op,e>(n,l={})\n        SegmentTree::n=(bits_msb(n))<<1;\n\
    \        tree.resize(SegmentTree::n*2,e());\n        for(int i=0;i<(int)l.size();i++)tree[SegmentTree::n+i]=l[i];\n\
    \        for(int i=SegmentTree::n-1;i>0;i--)tree[i]=op(tree[i<<1],tree[(i<<1)+1]);\n\
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
    \ v ^ (v >> 1);\n    }\n};\n#line 7 \"verify/aoj/segment-tree.test.cpp\"\n\nusing\
    \ T = long long;\nT op(T a,T b){\n    return min(a,b);\n};\nT e(){return (1ll<<31)-1;}\n\
    \nint main(){\n    int n,q;cin>>n>>q;\n    SegmentTree<T,op,e> sg(n);\n\n    while(q--){\n\
    \        int com,x,y;cin>>com>>x>>y;\n        if(com==0){\n            sg.set(x-1,y);\n\
    \        }else{\n            cout<<sg.prod(x-1,y)<<endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../segment-tree/segment-tree.hpp\"\
    \n\nusing T = long long;\nT op(T a,T b){\n    return min(a,b);\n};\nT e(){return\
    \ (1ll<<31)-1;}\n\nint main(){\n    int n,q;cin>>n>>q;\n    SegmentTree<T,op,e>\
    \ sg(n);\n\n    while(q--){\n        int com,x,y;cin>>com>>x>>y;\n        if(com==0){\n\
    \            sg.set(x-1,y);\n        }else{\n            cout<<sg.prod(x-1,y)<<endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - segment-tree/segment-tree.hpp
  isVerificationFile: true
  path: verify/aoj/segment-tree.test.cpp
  requiredBy: []
  timestamp: '2023-03-20 07:52:06-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/segment-tree.test.cpp
- /verify/verify/aoj/segment-tree.test.cpp.html
title: verify/aoj/segment-tree.test.cpp
---
