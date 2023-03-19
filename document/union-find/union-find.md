---
title: Union Find
documentation_of: ../../union-find/union-find.hpp
---

# 概要
素集合データ構造です  
詳しくはググってください

# 例
- __UnionFind(int N)__ := N頂点のUniFを作る $O(N)$
- __int find(int x)__ := 頂点xの親を探す $O(α)$
- __void unite(int x, int y)__ := 頂点xと頂点yを辺でつなげる $O(α)$
- __int size(int x)__ := 頂点xが属する木のサイズを返す $O(α)$
- __bool same(int x, int y)__ := 頂点xと頂点yが同じ木に含まれているか判定する $O(α)$
- __vector\<int\> members(int x)__ := 頂点xと同じ木に含まれている頂点を全て返す $O(αN)$
- __vector\<int\> roots()__ := 親を全て返す $O(αN)$
- __int grp_cnt()__ := 木の数を返す $O(1)$
- __unordered_map\<int,vector\<int\>\> grp_mem()__ := 親をkey、その木に含まれているすべての頂点のリストをvalueとしたunordered_mapを返す $O(αN)$
