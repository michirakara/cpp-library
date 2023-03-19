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
  bundledCode: "#line 1 \"segment-tree/segment-tree.hpp\"\n#include<vector>\n#include<functional>\n\
    template <class T>\nstruct SegmentTree{\n    int n;\n    std::vector<T> tree;\n\
    \    T id_el;\n    std::function<T(T,T)> func;\n    \n    SegmentTree(std::function<T(T,T)>\
    \ f,T id_el,int n,std::vector<T> l={}):func(f),id_el(id_el){\n        //SegmentTree(f,id_el,n,l={})\n\
    \        //\u30E2\u30CE\u30A4\u30C9\u306E\u95A2\u6570f\u3068\u5358\u4F4D\u5143\
    id_el\u3001\u3067\u9577\u3055n\u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3057\
    \u307E\u3059(n\u304C2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\u5FC5\u8981\u306F\
    \u306A\u3044)\n        //l\u3092\u4E0E\u3048\u308B\u3068\u521D\u671F\u5316\u3057\
    \u3066\u304F\u308C\u307E\u3059 O(N)\n        SegmentTree::n=(bits_msb(n))<<1;\n\
    \        tree.resize(SegmentTree::n*2,id_el);\n        for(int i=0;i<l.size();i++)tree[SegmentTree::n+i]=l[i];\n\
    \        for(int i=SegmentTree::n-1;i>0;i--)tree[i]=func(tree[i<<1],tree[(i<<1)+1]);\n\
    \    }\n\n    T at(int ind){\n        //O(1)\u3067\u30E9\u30F3\u30C0\u30E0\u30A2\
    \u30AF\u30BB\u30B9\n        return tree[n+ind];\n    }\n\n    void update(int\
    \ ind,T x){\n        //O(log N)\u3067t[ind]\u3092x\u306B\u3059\u308B\n       \
    \ ind+=n;\n        tree[ind]=x;\n        while(ind>1){\n            tree[ind>>1]=func(tree[ind],tree[ind^1]);\n\
    \            ind>>=1;\n        }\n    }\n\n    T query(int l, int r){\n      \
    \  //O(log N)\u3067t[l:r)\u306E\u30AF\u30A8\u30EA\n        T ret=id_el;\n    \
    \    l+=n;\n        r+=n;\n        while(l<r){\n            if(l&1){\n       \
    \         ret=func(ret,tree[l]);l++;\n            }\n            if(r&1){\n  \
    \              ret=func(ret,tree[r-1]);\n            }\n            r>>=1;\n \
    \           l>>=1;\n        }\n        return ret;\n    }\n\nprivate:\n    unsigned\
    \ int bits_msb( unsigned int v ){\n    v = v | (v >>  1);\n    v = v | (v >> \
    \ 2);\n    v = v | (v >>  4);\n    v = v | (v >>  8);\n    v = v | (v >> 16);\n\
    \    return v ^ (v >> 1);\n    }\n};\n"
  code: "#include<vector>\n#include<functional>\ntemplate <class T>\nstruct SegmentTree{\n\
    \    int n;\n    std::vector<T> tree;\n    T id_el;\n    std::function<T(T,T)>\
    \ func;\n    \n    SegmentTree(std::function<T(T,T)> f,T id_el,int n,std::vector<T>\
    \ l={}):func(f),id_el(id_el){\n        //SegmentTree(f,id_el,n,l={})\n       \
    \ //\u30E2\u30CE\u30A4\u30C9\u306E\u95A2\u6570f\u3068\u5358\u4F4D\u5143id_el\u3001\
    \u3067\u9577\u3055n\u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3057\u307E\u3059\
    (n\u304C2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\
    )\n        //l\u3092\u4E0E\u3048\u308B\u3068\u521D\u671F\u5316\u3057\u3066\u304F\
    \u308C\u307E\u3059 O(N)\n        SegmentTree::n=(bits_msb(n))<<1;\n        tree.resize(SegmentTree::n*2,id_el);\n\
    \        for(int i=0;i<l.size();i++)tree[SegmentTree::n+i]=l[i];\n        for(int\
    \ i=SegmentTree::n-1;i>0;i--)tree[i]=func(tree[i<<1],tree[(i<<1)+1]);\n    }\n\
    \n    T at(int ind){\n        //O(1)\u3067\u30E9\u30F3\u30C0\u30E0\u30A2\u30AF\
    \u30BB\u30B9\n        return tree[n+ind];\n    }\n\n    void update(int ind,T\
    \ x){\n        //O(log N)\u3067t[ind]\u3092x\u306B\u3059\u308B\n        ind+=n;\n\
    \        tree[ind]=x;\n        while(ind>1){\n            tree[ind>>1]=func(tree[ind],tree[ind^1]);\n\
    \            ind>>=1;\n        }\n    }\n\n    T query(int l, int r){\n      \
    \  //O(log N)\u3067t[l:r)\u306E\u30AF\u30A8\u30EA\n        T ret=id_el;\n    \
    \    l+=n;\n        r+=n;\n        while(l<r){\n            if(l&1){\n       \
    \         ret=func(ret,tree[l]);l++;\n            }\n            if(r&1){\n  \
    \              ret=func(ret,tree[r-1]);\n            }\n            r>>=1;\n \
    \           l>>=1;\n        }\n        return ret;\n    }\n\nprivate:\n    unsigned\
    \ int bits_msb( unsigned int v ){\n    v = v | (v >>  1);\n    v = v | (v >> \
    \ 2);\n    v = v | (v >>  4);\n    v = v | (v >>  8);\n    v = v | (v >> 16);\n\
    \    return v ^ (v >> 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree.hpp
  requiredBy: []
  timestamp: '2023-02-19 14:19:29-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree.hpp
- /library/segment-tree/segment-tree.hpp.html
title: segment-tree/segment-tree.hpp
---
