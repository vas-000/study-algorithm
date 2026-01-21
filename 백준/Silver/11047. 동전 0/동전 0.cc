#include <iostream>
#include <vector>

bool chkValRange(const int aVal, const int aMin, const int aMax){
    if( (aMin>aVal)|| (aVal> aMax)){
        return false;
    }
    return true;
}
int main()
{
    int N, K;
    std::cin >> N >> K;
    
    // 입력 범위 체크
    if( !chkValRange(N, 1, 10)){
        return -1;
    }
    
    if( !chkValRange(K, 1, 100000000)){
        return -1;
    }

    std::vector<int> A;
    int val;
    // A1 입력
    std::cin >> val;
    if( !chkValRange(val, 1, 1)){
        return -1;
    }
    A.push_back(val);

    // A2 입력
    std::cin >> val;
    if( !chkValRange(val, 1, 1'000'000)){
        return -1;
    }
    A.push_back(val);

    // A3 부터는 A2의 배수가 되어야 함. 
    for( int i{2}; i<N; ++i){
        std::cin>>val;
        if( !chkValRange(val, 1, 1'000'000)){
            return -1;
        }
        // A[1]의 배수가 되어야 함
        if( (val% A[1]) != 0){
            return -1;
        }

        //오름 차순이어야 한다. 
        if( A[i-1] > val){
            return -1;
        }

        A.push_back(val);
    }

    //가치 총합 K
    int RemaindK = K;
    int count=0;
    for( int i{A.size()-1}; i>=0;){
        int calc = RemaindK-A[i];
        if(calc< 0){
            --i;
        }
        else if( calc >= 0 ){
            count++;
            RemaindK = calc;
            if( RemaindK == 0){
                break;
            }
        }
    }

    std::cout<< count<< "\n";
    

    return 0;
}