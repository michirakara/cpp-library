---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/implicit-treap.test.cpp
    title: verify/aoj/implicit-treap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
  bundledCode: "#line 1 \"binary-search-tree/implicit-treap.hpp\"\n//\u53C2\u8003\
    \ https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n//Treap<T,op,e,F,mapping,composition,id>\
    \ hoge;\u3067\u521D\u671F\u5316\n#include <algorithm>\n#include <vector>\n\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)(),class F,T(*mapping)(F f,T x),F(*composition)(F f,F g),F(*id)()>\n\
    class ImplicitTreap{\n    struct Node{\n        T val,acc=e();\n        int priority;\n\
    \        int cnt=1;\n        F lazy=id();\n        bool rev=false;\n        Node\
    \ *l, *r;\n        Node(T val,int priority):val(val),priority(priority),l(nullptr),r(nullptr){};\n\
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
    \      t->val=mapping(t->lazy,t->val);\n            t->lazy=id();\n        }\n\
    \        update(t);\n    }\n\n    void split(Tree t, int key, Tree& l,Tree& r){\n\
    \        if(!t){\n            l=r=nullptr;\n            return;\n        }\n \
    \       pushdown(t);\n        int implicit_key=cnt(t->l)+1;\n        if(key<implicit_key){\n\
    \            split(t->l,key,l,t->l),r=t;\n        }else{\n            split(t->r,key-implicit_key,t->r,r),l=t;\n\
    \        }\n        update(t);\n    }\n\n    void insert(Tree& t,int key,Tree\
    \ item){\n        Tree t1,t2;\n        split(t,key,t1,t2);\n        merge(t1,t1,item);\n\
    \        merge(t,t1,t2);\n    }\n\n    void merge(Tree& t, Tree l, Tree r){\n\
    \        pushdown(l);\n        pushdown(r);\n        if(!l || !r){\n         \
    \   t=l?l:r;\n        }else if(l->priority>r->priority){\n            merge(l->r,l->r,r),t=l;\n\
    \        }else{\n            merge(r->l,l,r->l),t=r;\n        }\n        update(t);\n\
    \    }\n\n    void erase(Tree& t,int key){\n        Tree t1,t2,t3;\n        split(t,key+1,t1,t2);\n\
    \        split(t1,key,t1,t3);\n        merge(t,t1,t2);\n    }\n\n    T prod(Tree\
    \ t,int l,int r){\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n       \
    \ split(t2,r-l,t2,t3);\n        T ret=t2->acc;\n        merge(t2,t2,t3);\n   \
    \     merge(t,t1,t2);\n        return ret;\n    }\n\n    void apply(Tree t,int\
    \ l,int r,F x){\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n        split(t2,r-l,t2,t3);\n\
    \        t2->lazy=composition(t2->lazy,x);\n        t2->acc=mapping(x,t2->acc);\n\
    \        merge(t2,t2,t3);\n        merge(t,t1,t2);\n    }\n\n    void reverse(Tree\
    \ t,int l,int r){\n        if(l>r)return;\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n\
    \        split(t2,r-l,t2,t3);\n        t2->rev^=1;\n        merge(t2,t2,t3);\n\
    \        merge(t,t1,t2);\n    }\n\n    void rotate(Tree t,int l,int m,int r){\n\
    \        reverse(t,l,r);\n        reverse(t,l,l+r-m);\n        reverse(t,l+r-m,r);\n\
    \    }\n\n    void dump(Tree t) {\n        if (!t) return;\n        pushdown(t);\n\
    \        dump(t->l);\n        cout << t->val << \" \";\n        dump(t->r);\n\
    \    }\n\npublic:\n    ImplicitTreap() {}\n    ImplicitTreap(std::vector<T> as){\n\
    \        std::reverse(as.begin(),as.end());\n        for(T a:as){\n          \
    \  insert(0,a);\n        }\n    }\n\n    void insert(int pos,T val){\n       \
    \ //val\u3092pos\u306E\u5834\u6240\u306B\u8FFD\u52A0\u3059\u308B O(log N)\n  \
    \      insert(root,pos,new Node(val,rand()));\n    }\n\n    void erase(T pos){\n\
    \        //pos\u306B\u3042\u308B\u8981\u7D20\u3092\u6D88\u3059 O(log N)\n    \
    \    erase(root,pos);\n    }\n\n    int size(){\n        return cnt(root);\n \
    \   }\n\n    T operator[](int pos) {\n        Tree t1, t2, t3;\n        split(root,\
    \ pos + 1, t1, t2);\n        split(t1, pos, t1, t3);\n        T ret = t3->acc;\n\
    \        merge(t1, t1, t3);\n        merge(root, t1, t2);\n        return ret;\n\
    \    }\n\n    T prod(int l, int r){\n        //[l,r)\u306E\u533A\u9593 O(log N)\n\
    \        return prod(root,l,r);\n    }\n\n    void apply(int l,int r,F x){\n \
    \       apply(root,l,r,x);\n    }\n\n    void reverse(int l,int r){\n        reverse(root,l,r);\n\
    \    }\n\n    void rotate(int l,int m,int r){\n        rotate(root,l,m,r);\n \
    \   }\n\n    void dump(){\n        dump(root);cout<<endl;\n    }\n};\n"
  code: "//\u53C2\u8003 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n\
    //Treap<T,op,e,F,mapping,composition,id> hoge;\u3067\u521D\u671F\u5316\n#include\
    \ <algorithm>\n#include <vector>\n\ntemplate<class T,T(*op)(T,T),T(*e)(),class\
    \ F,T(*mapping)(F f,T x),F(*composition)(F f,F g),F(*id)()>\nclass ImplicitTreap{\n\
    \    struct Node{\n        T val,acc=e();\n        int priority;\n        int\
    \ cnt=1;\n        F lazy=id();\n        bool rev=false;\n        Node *l, *r;\n\
    \        Node(T val,int priority):val(val),priority(priority),l(nullptr),r(nullptr){};\n\
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
    \      t->val=mapping(t->lazy,t->val);\n            t->lazy=id();\n        }\n\
    \        update(t);\n    }\n\n    void split(Tree t, int key, Tree& l,Tree& r){\n\
    \        if(!t){\n            l=r=nullptr;\n            return;\n        }\n \
    \       pushdown(t);\n        int implicit_key=cnt(t->l)+1;\n        if(key<implicit_key){\n\
    \            split(t->l,key,l,t->l),r=t;\n        }else{\n            split(t->r,key-implicit_key,t->r,r),l=t;\n\
    \        }\n        update(t);\n    }\n\n    void insert(Tree& t,int key,Tree\
    \ item){\n        Tree t1,t2;\n        split(t,key,t1,t2);\n        merge(t1,t1,item);\n\
    \        merge(t,t1,t2);\n    }\n\n    void merge(Tree& t, Tree l, Tree r){\n\
    \        pushdown(l);\n        pushdown(r);\n        if(!l || !r){\n         \
    \   t=l?l:r;\n        }else if(l->priority>r->priority){\n            merge(l->r,l->r,r),t=l;\n\
    \        }else{\n            merge(r->l,l,r->l),t=r;\n        }\n        update(t);\n\
    \    }\n\n    void erase(Tree& t,int key){\n        Tree t1,t2,t3;\n        split(t,key+1,t1,t2);\n\
    \        split(t1,key,t1,t3);\n        merge(t,t1,t2);\n    }\n\n    T prod(Tree\
    \ t,int l,int r){\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n       \
    \ split(t2,r-l,t2,t3);\n        T ret=t2->acc;\n        merge(t2,t2,t3);\n   \
    \     merge(t,t1,t2);\n        return ret;\n    }\n\n    void apply(Tree t,int\
    \ l,int r,F x){\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n        split(t2,r-l,t2,t3);\n\
    \        t2->lazy=composition(t2->lazy,x);\n        t2->acc=mapping(x,t2->acc);\n\
    \        merge(t2,t2,t3);\n        merge(t,t1,t2);\n    }\n\n    void reverse(Tree\
    \ t,int l,int r){\n        if(l>r)return;\n        Tree t1,t2,t3;\n        split(t,l,t1,t2);\n\
    \        split(t2,r-l,t2,t3);\n        t2->rev^=1;\n        merge(t2,t2,t3);\n\
    \        merge(t,t1,t2);\n    }\n\n    void rotate(Tree t,int l,int m,int r){\n\
    \        reverse(t,l,r);\n        reverse(t,l,l+r-m);\n        reverse(t,l+r-m,r);\n\
    \    }\n\n    void dump(Tree t) {\n        if (!t) return;\n        pushdown(t);\n\
    \        dump(t->l);\n        cout << t->val << \" \";\n        dump(t->r);\n\
    \    }\n\npublic:\n    ImplicitTreap() {}\n    ImplicitTreap(std::vector<T> as){\n\
    \        std::reverse(as.begin(),as.end());\n        for(T a:as){\n          \
    \  insert(0,a);\n        }\n    }\n\n    void insert(int pos,T val){\n       \
    \ //val\u3092pos\u306E\u5834\u6240\u306B\u8FFD\u52A0\u3059\u308B O(log N)\n  \
    \      insert(root,pos,new Node(val,rand()));\n    }\n\n    void erase(T pos){\n\
    \        //pos\u306B\u3042\u308B\u8981\u7D20\u3092\u6D88\u3059 O(log N)\n    \
    \    erase(root,pos);\n    }\n\n    int size(){\n        return cnt(root);\n \
    \   }\n\n    T operator[](int pos) {\n        Tree t1, t2, t3;\n        split(root,\
    \ pos + 1, t1, t2);\n        split(t1, pos, t1, t3);\n        T ret = t3->acc;\n\
    \        merge(t1, t1, t3);\n        merge(root, t1, t2);\n        return ret;\n\
    \    }\n\n    T prod(int l, int r){\n        //[l,r)\u306E\u533A\u9593 O(log N)\n\
    \        return prod(root,l,r);\n    }\n\n    void apply(int l,int r,F x){\n \
    \       apply(root,l,r,x);\n    }\n\n    void reverse(int l,int r){\n        reverse(root,l,r);\n\
    \    }\n\n    void rotate(int l,int m,int r){\n        rotate(root,l,m,r);\n \
    \   }\n\n    void dump(){\n        dump(root);cout<<endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: binary-search-tree/implicit-treap.hpp
  requiredBy: []
  timestamp: '2023-03-19 19:39:12-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/implicit-treap.test.cpp
documentation_of: binary-search-tree/implicit-treap.hpp
layout: document
redirect_from:
- /library/binary-search-tree/implicit-treap.hpp
- /library/binary-search-tree/implicit-treap.hpp.html
title: binary-search-tree/implicit-treap.hpp
---
