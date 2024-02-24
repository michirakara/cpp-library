#include<vector>
#include<utility>
#include<cmath>

struct Grid{
    int h,w;
    std::vector<std::vector<char>> grid;

    Grid(std::vector<std::vector<char>> gr){
        h=gr.size();
        w=gr[0].size();
        grid=gr; 
    }
    Grid(int h,int w){
        Grid::h=h;
        Grid::w=w;
        grid=std::vector<std::vector<char>>(h,std::vector<char>(w,'.'));
    }

    void set(int h_idx,int w_idx,char c){
        grid[h_idx][w_idx]=c;
    }

    bool is_empty(int h_idx,int w_idx){
        if(0<=h_idx && h_idx<h && 0<=w_idx && w_idx<w && grid[h_idx][w_idx]=='.'){
            return true;
        }
        return false;
    }

    bool is_in_grid(int h_idx,int w_idx){
        if(0<=h_idx && h_idx<h && 0<=w_idx && w_idx<w){
            return true;
        }
        return false;
    }

    std::pair<int,int> retidx(int h_idx,int w_idx,int dx,int dy){
        return {h_idx+dx,w_idx+dy};
    }
    std::pair<int,int> retidx(int h_idx,int w_idx,char dir){
        if(dir=='R')return retidx(h_idx,w_idx,0,1);
        if(dir=='L')return retidx(h_idx,w_idx,0,-1);
        if(dir=='U')return retidx(h_idx,w_idx,-1,0);
        if(dir=='D')return retidx(h_idx,w_idx,1,0);
    }

    std::vector<std::pair<int,int>> next_4(int h_idx,int w_idx){
        std::vector<std::pair<int,int>> ret;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(std::abs(dx)+std::abs(dy)!=1)continue;
                std::pair<int,int> tmp=retidx(h_idx,w_idx,dx,dy);
                if(is_in_grid(tmp.first,tmp.second))ret.push_back(tmp);
            }
        }
        return ret;
    }
    std::vector<std::pair<int,int>> next_8(int h_idx,int w_idx){
        std::vector<std::pair<int,int>> ret;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                std::pair<int,int> tmp=retidx(h_idx,w_idx,dx,dy);
                if(is_in_grid(tmp.first,tmp.second))ret.push_back(tmp);
            }
        }
        return ret;
    }
};