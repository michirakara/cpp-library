---
title: Grid
documentation_of: ../../grid/grid.hpp
---

# 概要
グリッドの便利な関数を詰め込みました

# 例
- 初期化  
    - __Grid(int h,int w)__  
    h*wの`.`で初期化されたグリッドを作る
    - __Grid(vector<vector<char>> gr)__  
    grで初期化されたグリッドを作る
- __void set(int h,int w,char c)__  
    `grid[h][w]`を$c$にする  
    cが`#`と`.`以外のときの挙動は未定義です
- __bool is_empty(int h_idx, int w_idx)__  
    `grid[h_idx][w_idx]`が存在するかつ`.`ならtrueを返す
- __bool is_in_grid(int h_idx, int w_idx)__  
    `grid[h_idx][w_idx]`が存在するならtrueを返す
- __retidx__
    - __pair<int,int> retidx(int h_idx,int w_idx,int dx,int dy)__
    - __pair<int,int> retidx(int h_idx,int w_idx,char dir)__  
    大体想像通りのものを返します
- __vector<pair<int,int>> next_4(int h_idx,int w_idx)__  
    4方向でグリッド内のマス目を返します  
    グリッドの中身が何かは判定しないので`is_empty`を使ったりして判定してください
- __vector<pair<int,int>> next_8(int h_idx,int w_idx)__  
    ↑の8方向版です
