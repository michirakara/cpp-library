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
  bundledCode: "#line 1 \"segment-tree/lazy-segment-tree.hpp\"\n#include<vector>\n\
    #include<functional>\n#include<cassert>\ntemplate <class T,class K>\nstruct LazySegmentTree{\n\
    \    int n;\n    std::vector<T> tree;\n    std::vector<K> lazy;\n    T id_func;\n\
    \    K id_g;\n    std::function<T(T,T)> func;\n    std::function<T(T,K,int)> mapping;\n\
    \    std::function<K(K,K)> composition;\n    \n    LazySegmentTree(std::function<T(T,T)>\
    \ f,std::function<T(T,K,int)> mapping,std::function<K(K,K)> composition,T id_f,K\
    \ id_g,int n,std::vector<T> l={}):func(f),mapping(mapping),composition(composition),id_func(id_f),id_g(id_g){\n\
    \        //SegmentTree(f,g,id_f,id_g,n,l={})\n        //\u533A\u9593\u53D6\u5F97\
    \u306E\u95A2\u6570f\u3068\u5358\u4F4D\u5143id_f\u3001\u533A\u9593\u66F4\u65B0\u306E\
    \u95A2\u6570mapping,composition\u3068composition\u306E\u5358\u4F4D\u5143id_g\u3067\
    \u9577\u3055n\u306E\u9045\u5EF6\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3057\u307E\
    \u3059(n\u304C2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\
    \u3044)\n        //l\u3092\u4E0E\u3048\u308B\u3068\u521D\u671F\u5316\u3057\u3066\
    \u304F\u308C\u307E\u3059 O(N)\n        //mapping(a,b,c)\u306F\u9577\u3055c\u306E\
    \u533A\u9593a\u306Blazy\u306B\u5165\u3063\u3066\u3044\u308B\u8981\u7D20b\u3092\
    \u4F5C\u7528\u3055\u305B\u308B\u3068\u304D\u306E\u95A2\u6570\u3067\u3059\n   \
    \     //composition(a,b)\u306F\u5143\u304B\u3089lazy\u306Ba\u304C\u3042\u3063\u305F\
    \u3068\u304D\u306Bb\u3068\u5408\u4F53\u3055\u305B\u308B\u3068\u304D\u306E\u95A2\
    \u6570\n        LazySegmentTree::n=(bits_msb(n))<<1;\n        tree.resize(2*LazySegmentTree::n,id_func);\n\
    \        lazy.resize(LazySegmentTree::n,id_g);\n        for(int i=0;i<l.size();i++)tree[LazySegmentTree::n+i]=l[i];\n\
    \        for(int i=LazySegmentTree::n-1;i>0;i--)tree[i]=func(tree[i<<1],tree[(i<<1)+1]);\n\
    \    }\n\n    /*T at(int ind){\n        //O(1)\u3067\u30E9\u30F3\u30C0\u30E0\u30A2\
    \u30AF\u30BB\u30B9\n        return tree[n+ind];\n    }*/\n\n    void eval(int\
    \ ind,int l,int r){\n        int tmp=ind;\n        std::vector<int> inds;\n  \
    \      tmp>>=1;\n        while(tmp!=0){inds.push_back(tmp);tmp>>=1;}\n       \
    \ for(int i=inds.size()-1;i>=0;i--){\n            if(lazy[inds[i]]!=id_g){\n \
    \               if(n>(inds[i]<<1)){\n                    lazy[inds[i]<<1]=composition(lazy[inds[i]<<1],lazy[inds[i]]);\n\
    \                    lazy[(inds[i]<<1)+1]=composition(lazy[(inds[i]<<1)+1],lazy[inds[i]]);\n\
    \                }\n                tree[inds[i]<<1]=mapping(tree[inds[i]<<1],lazy[inds[i]],(n/bits_msb(inds[i]))/2);\n\
    \                tree[(inds[i]<<1)+1]=mapping(tree[(inds[i]<<1)+1],lazy[inds[i]],(n/bits_msb(inds[i]))/2);\n\
    \                lazy[inds[i]]=id_g;\n            }\n        }\n    }\n\n    void\
    \ update(int l, int r,K x,int ind=1,int nl=0,int nr=-1){\n        //O(log N)\u3067\
    t[l,r)\u3092\u305D\u308C\u305E\u308Cmapping(t[i],x,1)\u306B\u3059\u308B\n    \
    \    if(nr==-1)nr=n;\n        \n        if(nr<=l || r<=nl)return;\n\n        if(l<=nl\
    \ && nr<=r){\n            eval(ind,l,r);\n            tree[ind]=mapping(tree[ind],x,nr-nl);\n\
    \            if(n>ind)lazy[ind]=composition(lazy[ind],x);\n            ind>>=1;\n\
    \            while(ind!=0){tree[ind]=func(tree[ind<<1],tree[(ind<<1)+1]);ind>>=1;}\n\
    \        }else{\n            update(l,r,x,ind<<1,nl,nl+(nr-nl)/2);\n         \
    \   update(l,r,x,(ind<<1)+1,nr-(nr-nl)/2,nr);\n        }\n        return;\n  \
    \  }\n\n    T query(int l, int r,int ind=1,int nl=0,int nr=-1){\n        //O(log\
    \ N)\u3067t[l:r)\u306E\u30AF\u30A8\u30EA\n        if(nr==-1)nr=n;\n\n        if(nr<=l\
    \ || r<=nl)return id_func;\n\n        if(l<=nl && nr<=r){\n            eval(ind,nl,nr);\n\
    \            return tree[ind];\n        }else{\n            return func(query(l,r,ind<<1,nl,nl+(nr-nl)/2),query(l,r,(ind<<1)+1,nr-(nr-nl)/2,nr));\n\
    \        }\n    }\n\nprivate:\n    unsigned int bits_msb( unsigned int v ){\n\
    \    v = v | (v >>  1);\n    v = v | (v >>  2);\n    v = v | (v >>  4);\n    v\
    \ = v | (v >>  8);\n    v = v | (v >> 16);\n    return v ^ (v >> 1);\n    }\n\
    };\n"
  code: "#include<vector>\n#include<functional>\n#include<cassert>\ntemplate <class\
    \ T,class K>\nstruct LazySegmentTree{\n    int n;\n    std::vector<T> tree;\n\
    \    std::vector<K> lazy;\n    T id_func;\n    K id_g;\n    std::function<T(T,T)>\
    \ func;\n    std::function<T(T,K,int)> mapping;\n    std::function<K(K,K)> composition;\n\
    \    \n    LazySegmentTree(std::function<T(T,T)> f,std::function<T(T,K,int)> mapping,std::function<K(K,K)>\
    \ composition,T id_f,K id_g,int n,std::vector<T> l={}):func(f),mapping(mapping),composition(composition),id_func(id_f),id_g(id_g){\n\
    \        //SegmentTree(f,g,id_f,id_g,n,l={})\n        //\u533A\u9593\u53D6\u5F97\
    \u306E\u95A2\u6570f\u3068\u5358\u4F4D\u5143id_f\u3001\u533A\u9593\u66F4\u65B0\u306E\
    \u95A2\u6570mapping,composition\u3068composition\u306E\u5358\u4F4D\u5143id_g\u3067\
    \u9577\u3055n\u306E\u9045\u5EF6\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3057\u307E\
    \u3059(n\u304C2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\
    \u3044)\n        //l\u3092\u4E0E\u3048\u308B\u3068\u521D\u671F\u5316\u3057\u3066\
    \u304F\u308C\u307E\u3059 O(N)\n        //mapping(a,b,c)\u306F\u9577\u3055c\u306E\
    \u533A\u9593a\u306Blazy\u306B\u5165\u3063\u3066\u3044\u308B\u8981\u7D20b\u3092\
    \u4F5C\u7528\u3055\u305B\u308B\u3068\u304D\u306E\u95A2\u6570\u3067\u3059\n   \
    \     //composition(a,b)\u306F\u5143\u304B\u3089lazy\u306Ba\u304C\u3042\u3063\u305F\
    \u3068\u304D\u306Bb\u3068\u5408\u4F53\u3055\u305B\u308B\u3068\u304D\u306E\u95A2\
    \u6570\n        LazySegmentTree::n=(bits_msb(n))<<1;\n        tree.resize(2*LazySegmentTree::n,id_func);\n\
    \        lazy.resize(LazySegmentTree::n,id_g);\n        for(int i=0;i<l.size();i++)tree[LazySegmentTree::n+i]=l[i];\n\
    \        for(int i=LazySegmentTree::n-1;i>0;i--)tree[i]=func(tree[i<<1],tree[(i<<1)+1]);\n\
    \    }\n\n    /*T at(int ind){\n        //O(1)\u3067\u30E9\u30F3\u30C0\u30E0\u30A2\
    \u30AF\u30BB\u30B9\n        return tree[n+ind];\n    }*/\n\n    void eval(int\
    \ ind,int l,int r){\n        int tmp=ind;\n        std::vector<int> inds;\n  \
    \      tmp>>=1;\n        while(tmp!=0){inds.push_back(tmp);tmp>>=1;}\n       \
    \ for(int i=inds.size()-1;i>=0;i--){\n            if(lazy[inds[i]]!=id_g){\n \
    \               if(n>(inds[i]<<1)){\n                    lazy[inds[i]<<1]=composition(lazy[inds[i]<<1],lazy[inds[i]]);\n\
    \                    lazy[(inds[i]<<1)+1]=composition(lazy[(inds[i]<<1)+1],lazy[inds[i]]);\n\
    \                }\n                tree[inds[i]<<1]=mapping(tree[inds[i]<<1],lazy[inds[i]],(n/bits_msb(inds[i]))/2);\n\
    \                tree[(inds[i]<<1)+1]=mapping(tree[(inds[i]<<1)+1],lazy[inds[i]],(n/bits_msb(inds[i]))/2);\n\
    \                lazy[inds[i]]=id_g;\n            }\n        }\n    }\n\n    void\
    \ update(int l, int r,K x,int ind=1,int nl=0,int nr=-1){\n        //O(log N)\u3067\
    t[l,r)\u3092\u305D\u308C\u305E\u308Cmapping(t[i],x,1)\u306B\u3059\u308B\n    \
    \    if(nr==-1)nr=n;\n        \n        if(nr<=l || r<=nl)return;\n\n        if(l<=nl\
    \ && nr<=r){\n            eval(ind,l,r);\n            tree[ind]=mapping(tree[ind],x,nr-nl);\n\
    \            if(n>ind)lazy[ind]=composition(lazy[ind],x);\n            ind>>=1;\n\
    \            while(ind!=0){tree[ind]=func(tree[ind<<1],tree[(ind<<1)+1]);ind>>=1;}\n\
    \        }else{\n            update(l,r,x,ind<<1,nl,nl+(nr-nl)/2);\n         \
    \   update(l,r,x,(ind<<1)+1,nr-(nr-nl)/2,nr);\n        }\n        return;\n  \
    \  }\n\n    T query(int l, int r,int ind=1,int nl=0,int nr=-1){\n        //O(log\
    \ N)\u3067t[l:r)\u306E\u30AF\u30A8\u30EA\n        if(nr==-1)nr=n;\n\n        if(nr<=l\
    \ || r<=nl)return id_func;\n\n        if(l<=nl && nr<=r){\n            eval(ind,nl,nr);\n\
    \            return tree[ind];\n        }else{\n            return func(query(l,r,ind<<1,nl,nl+(nr-nl)/2),query(l,r,(ind<<1)+1,nr-(nr-nl)/2,nr));\n\
    \        }\n    }\n\nprivate:\n    unsigned int bits_msb( unsigned int v ){\n\
    \    v = v | (v >>  1);\n    v = v | (v >>  2);\n    v = v | (v >>  4);\n    v\
    \ = v | (v >>  8);\n    v = v | (v >> 16);\n    return v ^ (v >> 1);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2023-02-21 19:40:14-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/lazy-segment-tree.hpp
- /library/segment-tree/lazy-segment-tree.hpp.html
title: segment-tree/lazy-segment-tree.hpp
---
