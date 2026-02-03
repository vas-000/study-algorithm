#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

bool ChkRange(const int val, const int aMin, const int aMax){
    if( (val< aMin) && (val > aMax)){
        return false;
    }
    return true;
}

bool InputData(const int N, std::vector<std::string>& src){
    std::string coins;
    std::cin>>coins;
    if( coins.length() != N){
    return false;
    }
    src.push_back(coins);
    return true;
}


int main(){
    std::string strFormat;
    std::cin >> strFormat;
    if( strFormat.length() > 4){
        // 형식은 길이가 4보다 작거나 같다.
        return 0;
    }
    for(int i{}; i<strFormat.length(); ++i){
        if( (strFormat.at(i)!='c') && (strFormat.at(i)!='d')){
            //형식은 c, d 이어야 함.
            return 0;
        }
    }

    int calc=0;
    std::vector<int> values;
    for(int i{}; i<strFormat.length(); ++i){
        auto ch = strFormat.at(i);
        if(ch == 'c'){
            values.push_back(26);
        }
        else if( ch == 'd'){
            values.push_back(10);
        }
    }
    calc = values[0];
    for( int i{1}; i< values.size(); ++i){
        if(values[i-1]==values[i]){
            calc= calc*(values[i]-1);
            continue;
        }
        else{
            calc = calc*values[i];
        }
    }

    std::cout<<calc<<"\n"; 
    
    return 0;
}