#include <iostream>
#include <vector>
#include <algorithm>

bool chkValRange(const int aVal, const int aMin, const int aMax){
    if( (aMin>aVal)|| (aVal> aMax)){
        return false;
    }
    return true;
}
int main()
{
    int N;
    std::cin >> N;
    
    // 입력 범위 체크
    if( !chkValRange(N, 1, 1'000)){
        return -1;
    }

    std::vector<int> P;
    int val;
    for( int i{}; i<N; ++i){
        std::cin>>val;
        if( !chkValRange(val, 1, 1'000)){
            return -1;
        }
        P.push_back(val);
    }
    std::sort(P.begin(), P.end());
    std::vector<int> dp;
    dp.push_back(P[0]);

    for(int i{1}; i< P.size(); ++i){
        int val = dp[i-1]+P[i];
        dp.push_back(val);
    }
    int sum=0;
    for(auto val: dp){
        sum+=val;
    }
    std::cout<< sum<< "\n";
    
    return 0;
}