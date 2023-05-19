#include<vector>
struct Doubling{
    std::vector<std::vector<int>> dp;
    Doubling(std::vector<int> next){
        dp.resize(64);
        for(int i=0;i<64;i++){
            dp[i].resize((int)next.size());
        }
        for(int i=0;i<(int)next.size();i++){
            dp[0][i]=next[i];
        }

        for(int i=0;i<63;i++){
            for(int j=0;j<(int)next.size();j++){
                dp[i+1][j]=dp[i][dp[i][j]];
            }
        }
    }

    int query(int start,long long turn){
        int res=start;
        for(int i=0;i<64;i++){
            if(turn&(1ll<<(long long)i)){
                res=dp[i][res];
            }
        }
        return res;
    }
};