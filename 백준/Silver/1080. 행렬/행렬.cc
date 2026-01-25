#include <iostream>
#include <queue>
#include <vector>
#include <map>

bool ChkRange(const int val, const int aMin, const int aMax){
    if( (val< aMin) && (val > aMax)){
        return false;
    }
    return true;
}

bool InputData(const int N, const int M, std::vector<std::string>& src){
   std::string row;
    for(int i{}; i< N; ++i){
        std::cin>>row;
        if(row.length()!=M){
            return false;
        }
        src.push_back(row);
    }
    return true;
}

bool Mask(int startRow, int startCol, std::vector<std::string>& src){
// 3 * 3 마스크를 한다.
    int outRangeRow = startRow+3;
    int outRangeCol = startCol+3;

    // 변경 불가능하다.
    if( src.size() < outRangeRow){
        return false;
    }
    if( src[0].length() < outRangeCol){
        return false;
    }
    for( int i{startRow}; i< outRangeRow; ++i){
        for(int j{startCol}; j<outRangeCol; ++j){
            if(src[i].at(j)=='0'){
                src[i].at(j)='1';
            }
            else{
                src[i].at(j)='0';
            }
        }
    }

    return true;
}
int main(){
    int N, M;
    std::cin >> N >> M;
    if( !ChkRange(N, 1, 50)){
        return 0;
    }

    if( !ChkRange(M, 1, 50)){
        return 0;
    }
    std::vector<std::string> A;
    std::vector<std::string> B;

    if(!InputData(N, M, A)){
        return -1;
    }   
    if(!InputData(N, M, B)){
        return -1;
    }

    //Process
    int count=0;
    bool exit=false;
    for(int row{}; row< N; ++row){
        for(int col{}; col<M; ++col){
            if(A[row][col] == B[row][col]){
                continue;
            }

            if(!Mask(row, col, A)){
                exit=true;
                break;
            }
            else{
                count+=1;
            }
        }
        if( exit == true){
            break;
        }
    }

    if( exit == true){
        count = -1;
    }
    
    std::cout<< count<<"\n";
    return 0;
}