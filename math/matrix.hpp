#include<vector>
template<class T>
struct Matrix{
    std::vector<std::vector<T>> internal_matrix;
    
    Matrix(int H,int W,T x=0):internal_matrix(H,std::vector<T>(W,x)){}

    int height() const {
        return (int)internal_matrix.size();
    }

    int width() const {
        return (int)internal_matrix[0].size();
    }

    inline const std::vector<T> &operator[](int idx)const{
        return internal_matrix.at(idx);
    }

    inline std::vector<T> &operator[](int idx){
        return internal_matrix.at(idx);
    }

    Matrix &operator+=(const Matrix &other){
        for(int i=0;i<height();i++){
            for(int j=0;j<width();j++){
                (*this)[i][j]+=other[i][j];
            }
        }
        return *this;
    }

    Matrix &operator-=(const Matrix &other){
        for(int i=0;i<height();i++){
            for(int j=0;j<width();j++){
                (*this)[i][j]-=other[i][j];
            }
        }
        return *this;
    }

    Matrix &operator*=(const Matrix &other){
        int l=height(),m=width(),n=other.width();
        std::vector<std::vector<T>> ret(l,std::vector<T>(n,0));
        for(int i=0;i<l;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    ret[i][j]+=(*this)[i][k]*other[k][j];
                }
            }
        }
        internal_matrix.swap(ret);
        return *this;
    }

    Matrix pow(long long p){
        //行列の掛け算の単位元はM[i][i]=1(0<i<N),それ以外のマスが0の行列
        Matrix ret=Matrix<T>(height(),height(),0);
        for(int i=0;i<height();i++)ret[i][i]=1;
        while(p>0){
            if(p&1)ret*=*this;
            *this*=*this;
            p>>=1ll;
        }
        return ret;
    }

    Matrix operator+(const Matrix &other) const {
        return (Matrix(*this)+=other);
    }

    Matrix operator-(const Matrix &other) const {
        return (Matrix(*this)-=other);
    }

    Matrix operator*(const Matrix &other) const {
        return (Matrix(*this)*=other);
    }
};