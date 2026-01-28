#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

bool chkValRange(const int aVal, const int aMin, const int aMax){
    if( (aMin>aVal)|| (aVal> aMax)){
        return false;
    }
    return true;
}
int main()
{
    int N; // 회의 수
    std::cin >> N;
    
    // 입력 범위 체크
    if( !chkValRange(N, 1, 100'000)){
        return -1;
    }

    std::vector<std::pair<int, int>> I; // 회의
    for( int i{}; i<N; ++i){
        int nStart, nEnd;
        std::cin>>nStart>>nEnd;
        if( !chkValRange(nStart, 0, 2'147'483'647)){
            return -1;
        }

        if( !chkValRange(nEnd, 0, 2'147'483'647)){
            return -1;
        }
        // 시작시간이 종료시간 보다 클경우 예외
        if(nStart > nEnd){
            return -1;
        }

        // 끝시간을 기준으로 정렬하기 위해 자료를 
        // (종료시간, 시작시간)으로 만든다.  
        I.push_back({nEnd, nStart});
    }
    
    std::sort(I.begin(), I.end());
    int nSize = I.size();
    
    int nMax=1;
    auto pick = I[0];
    for( int i{1}; i<nSize; ++i){
        if(pick.first > I[i].second){
            continue;
        }
        pick = I[i];
        nMax++;
    }
    
    std::cout<< nMax << "\n";
    
    return 0;
}