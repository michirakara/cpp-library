#include "math/matrix.hpp"
#include<vector>
#include<cassert>
#include<utility>
template<class T>
struct GaussJordan{
    Matrix<T> mat;

    GaussJordan(Matrix<T> system):mat(system){
        assert(mat.height()==mat.width()-1);
    }
    std::vector<T> solve(){
        for(int i=0;i<mat.width()-1;i++){
            for(int j=i;j<mat.height();j++){
                if(mat[j][i]!=0){
                    std::swap(mat[j],mat[i]);
                    T to_div=mat[i][i];
                    for(int k=0;k<mat.width();k++){
                        mat[i][k]/=to_div;
                    }
                    for(int k=0;k<mat.height();k++){
                        if(i==k)continue;
                        T mul_by=-mat[k][i];
                        for(int l=0;l<mat.width();l++){
                            mat[k][l]+=mul_by*mat[i][l];
                        }
                    }
                    break;
                }
            }
        }
        std::vector<T> ret(mat.height());
        for(int i=0;i<mat.height();i++){
            ret[i]=mat[i][mat.width()-1];
        }
        return ret;
    }
};