---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: binary-search-tree/implicit-treap.hpp
    title: binary-search-tree/implicit-treap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
  bundledCode: "#line 1 \"verify/aoj/implicit-treap.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"binary-search-tree/implicit-treap.hpp\"\n//\u53C2\
    \u8003 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n//Treap<T,op,e,F,mapping,composition,id>\
    \ hoge;\u3067\u521D\u671F\u5316\ntemplate<class T,T(*op)(T,T),T(*e)(),class F,T(*mapping)(F\
    \ f,T x),F(*composition)(F f,F g),F(*id)()>\nclass ImplicitTreap{\n    struct\
    \ Node{\n        T val;\n        int priority;\n        int cnt=1;\n        T\
    \ acc;\n        F lazy=id();\n        bool rev=false;\n        Node *l, *r;\n\
    \        Node(T val,int priority):val(val),priority(priority),acc(val),l(nullptr),r(nullptr){};\n\
    \    }\n    *root=nullptr;\n    using Tree=Node *;\n\n    int cnt(Tree t) {\n\
    \        return t ? t->cnt : 0;\n    }\n\n    T acc(Tree t){\n        return t\
    \ ? t->acc : e();\n    }\n\n    void update(Tree t){\n        if(t){\n       \
    \     t->cnt=1+cnt(t->l)+cnt(t->r);\n            t->acc=op(t->val,op(acc(t->l),acc(t->r)));\n\
    \        }\n    }\n\n    void pushdown(Tree t){\n        if(t && t->rev){\n  \
    \          t->rev=false;\n            swap(t->l,t->r);\n            if(t->l)t->l->rev^=1;\n\
    \            if(t->r)t->r->rev^=1;\n        }\n        if(t && t->lazy!=id()){\n\
    \            if(t->l){\n                t->l->lazy=composition(t->l->lazy,t->lazy);\n\
    \                t->l->acc=mapping(t->lazy,t->l->acc);\n            }\n      \
    \      if(t->r){\n                t->r->lazy=composition(t->r->lazy,t->lazy);\n\
    \                t->r->acc=mapping(t->lazy,t->r->acc);\n            }\n      \
    \      t->val=mapping(t->lazy,t->val);\n            t->lazy=0;\n        }\n  \
    \      update(t);\n    }\n\n    void split(Tree t, T key, Tree& l,Tree& r){\n\
    \        if(!t){\n            l=r=nullptr;\n            return;\n        }\n \
    \       pushdown(t);\n        int implicit_key=cnt(t->l)+1;\n        if(key<implicit_key){\n\
    \            split(t->l,key,l,t->l),r=t;\n        }else{\n            split(t->r,key-implicit_key,t->r,r),l=t;\n\
    \        }\n        update(t);\n    }\n\n    void merge(Tree& t, Tree l, Tree\
    \ r){\n        pushdown(l);\n        pushdown(r);\n        if(!l || !r){\n   \
    \         t=l?l:r;\n        }else if(l->priority>r->priority){\n            merge(l->r,l->r,r),t=l;\n\
    \        }else{\n            merge(r->l,l,r->l),t=r;\n        }\n        update(t);\n\
    \    }\n\n    void insert(Tree& t,int key,Tree item){\n        Tree t1,t2;\n \
    \       split(t,key,t1,t2);\n        merge(t1,t1,item);\n        merge(t,t1,t2);\n\
    \    }\n\n    void erase(Tree& t,int key){\n        Tree t1,t2,t3;\n        split(t,key+1,t1,t2);\n\
    \        split(t1,key,t1,t3);\n        merge(t,t1,t2);\n    }\n\n    T at(Tree&\
    \ t, int ind, int ni){\n        if(!t)return -1;\n        if(ni==ind){\n     \
    \       return t->val;\n        }else if(ind<ni){\n            return at(t->l,ind,ni-1-cnt(t->l->r));\n\
    \        }else{\n            return at(t->r,ind,ni+1+cnt(t->r->l));\n        }\n\
    \    }\n\n    T prod(Tree t,int l,int r){\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n\
    \        split(t2,r-l,t2,t3);\n        T ret=t2->acc;\n        merge(t2,t2,t3);\n\
    \        merge(t,t1,t2);\n        return ret;\n    }\n\n    void apply(Tree t,int\
    \ l,int r,F x){\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n        split(t2,r-l,t2,t3);\n\
    \        t2->lazy=composition(t2->lazy,x);\n        t2->acc=mapping(x,t2->acc);\n\
    \        merge(t2,t2,t3);\n        merge(t,t1,t2);\n    }\n\n    void reverse(Tree\
    \ t,int l,int r){\n        if(l>r)return;\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n\
    \        split(t2,r-l,t2,t3);\n        t2->rev^=1;\n        merge(t2,t2,t3);\n\
    \        merge(t,t1,t2);\n    }\n\n    void rotate(Tree t,int l,int m,int r){\n\
    \        reverse(t,l,r);\n        reverse(t,l,l+r-m);\n        reverse(t,l+r-m,r);\n\
    \    }\n\npublic:\n    void insert(int pos,T val){\n        //val\u3092pos\u306E\
    \u5834\u6240\u306B\u8FFD\u52A0\u3059\u308B O(log N)\n        insert(root,pos,new\
    \ Node(val,rand()));\n    }\n\n    void erase(T pos){\n        //pos\u306B\u3042\
    \u308B\u8981\u7D20\u3092\u6D88\u3059 O(log N)\n        erase(root,pos);\n    }\n\
    \n    int size(){\n        return cnt(root);\n    }\n\n    T operator[](int ind){\n\
    \        //index\u3067\u30E9\u30F3\u30C0\u30E0\u30A2\u30AF\u30BB\u30B9 O(log N)\n\
    \        return prod(root,ind,ind+1);\n    }\n\n    T prod(int l, int r){\n  \
    \      //[l,r)\u306E\u533A\u9593 O(log N)\n        return prod(root,l,r);\n  \
    \  }\n\n    void apply(int l,int r,F x){\n        apply(root,l,r,x);\n    }\n\n\
    \    void reverse(int l,int r){\n        reverse(root,l,r);\n    }\n\n    void\
    \ rotate(int l,int m,int r){\n        rotate(root,l,m,r);\n    }\n};\n#line 7\
    \ \"verify/aoj/implicit-treap.test.cpp\"\n\nusing S = long long;\nusing F = long\
    \ long;\n\nconst S INF = 8e18;\nconst F ID = 8e18;\n\nS op(S a, S b){ return std::min(a,\
    \ b); }\nS e(){ return INF; }\nS mapping(F f, S x){ return (f == ID ? x : f);\
    \ }\nF composition(F f, F g){ return (f == ID ? g : f); }\nF id(){ return ID;\
    \ }\n\nint main(){\n    int n,q;\n    cin>>n>>q;\n    \n    ImplicitTreap<S,op,e,F,mapping,composition,id>\
    \ set;\n    for(int i=0;i<n;i++){\n        int x;cin>>x;set.insert(set.size(),x);\n\
    \    }\n\n    for(int i=0;i<q;i++){\n        int x,y,z;\n        cin>>x>>y>>z;\n\
    \        if(x==0){\n            set.rotate(y,z,z+1);\n        }else if(x==1){\n\
    \            cout<<set.prod(y,z+1)<<endl;\n        }else{\n            set.apply(y,y+1,z);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../binary-search-tree/implicit-treap.hpp\"\
    \n\nusing S = long long;\nusing F = long long;\n\nconst S INF = 8e18;\nconst F\
    \ ID = 8e18;\n\nS op(S a, S b){ return std::min(a, b); }\nS e(){ return INF; }\n\
    S mapping(F f, S x){ return (f == ID ? x : f); }\nF composition(F f, F g){ return\
    \ (f == ID ? g : f); }\nF id(){ return ID; }\n\nint main(){\n    int n,q;\n  \
    \  cin>>n>>q;\n    \n    ImplicitTreap<S,op,e,F,mapping,composition,id> set;\n\
    \    for(int i=0;i<n;i++){\n        int x;cin>>x;set.insert(set.size(),x);\n \
    \   }\n\n    for(int i=0;i<q;i++){\n        int x,y,z;\n        cin>>x>>y>>z;\n\
    \        if(x==0){\n            set.rotate(y,z,z+1);\n        }else if(x==1){\n\
    \            cout<<set.prod(y,z+1)<<endl;\n        }else{\n            set.apply(y,y+1,z);\n\
    \        }\n    }\n}"
  dependsOn:
  - binary-search-tree/implicit-treap.hpp
  isVerificationFile: true
  path: verify/aoj/implicit-treap.test.cpp
  requiredBy: []
  timestamp: '2023-03-19 17:47:11-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/implicit-treap.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/implicit-treap.test.cpp
- /verify/verify/aoj/implicit-treap.test.cpp.html
title: verify/aoj/implicit-treap.test.cpp
---
