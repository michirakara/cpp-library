#include<iostream>
#include<utility>

template <int mod>
struct modint{
    long long internal_val;
    modint():internal_val(0){}
    modint(long long val):internal_val(val>=0 ? val%mod : (mod-(-val)%mod)%mod){}

    modint& operator++(){
        internal_val++;
        if(internal_val==mod)internal_val=0;
        return *this;
    }
    modint& operator--(){
        if(internal_val==0)internal_val=mod;
        internal_val--;
        return *this;
    }
    modint operator++(int){
        modint ret=*this;
        ++*this;
        return ret;
    }
    modint operator--(int){
        modint ret=*this;
        --*this;
        return ret;
    }
    modint& operator+=(const modint &other){
        if((internal_val+=other.internal_val)>=mod)internal_val-=mod;
        return *this;
    }
    modint& operator-=(const modint &other){
        if((internal_val+=mod-other.internal_val)>=mod)internal_val-=mod;
        return *this;
    }
    modint& operator*=(const modint &other){
        internal_val=internal_val*other.internal_val%mod;
        return *this;
    }
    modint& operator/=(const modint &other){
        *this*=other.inv();
        return *this;
    }

    modint operator-() const {return modint(-internal_val);}
    modint operator+() const {return modint(internal_val);}
    modint operator+(const modint &other) const {return modint(*this)+=other;}
    modint operator-(const modint &other) const {return modint(*this)-=other;}
    modint operator*(const modint &other) const {return modint(*this)*=other;}
    modint operator/(const modint &other) const {return modint(*this)/=other;}
    bool operator==(const modint &other) const {return internal_val==other.internal_val;}
    bool operator!=(const modint &other) const {return internal_val!=other.internal_val;}
    
    modint inv()const{
        int a=internal_val,b=mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            std::swap(a-=t*b,b);
            std::swap(u-=t*v,v);
        }
        return modint(u);
    }

    modint pow(long long n) const {
        modint ret(1),mul(internal_val);
        while(n>0){
            if(n&1)ret*=mul;
            mul*=mul;
            n>>=1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const modint &other){
        return os<<other.internal_val;
    }
    friend std::istream &operator>>(std::istream &is, modint &other){
        long long t;
        is>>t;
        other=modint<mod>(t);
        return (is);
    }

    static int get_mod(){return mod;}
};