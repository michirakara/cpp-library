---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/segment-tree.test.cpp
    title: verify/aoj/segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment-tree/segment-tree.hpp\"\n#include<vector>\n#include<functional>\n\
    template <class T,T(*op)(T,T),T(*e)()>\nstruct SegmentTree{\n    int n;\n    std::vector<T>\
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
    \ v ^ (v >> 1);\n    }\n};\n"
  code: "#include<vector>\n#include<functional>\ntemplate <class T,T(*op)(T,T),T(*e)()>\n\
    struct SegmentTree{\n    int n;\n    std::vector<T> tree;\n    \n    SegmentTree(int\
    \ n,std::vector<T> l={}){\n        //SegmentTree<T,op,e>(n,l={})\n        SegmentTree::n=(bits_msb(n))<<1;\n\
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
    \ v ^ (v >> 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree.hpp
  requiredBy: []
  timestamp: '2023-03-20 07:52:06-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/segment-tree.test.cpp
documentation_of: segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree.hpp
- /library/segment-tree/segment-tree.hpp.html
title: segment-tree/segment-tree.hpp
---
