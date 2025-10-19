#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <random>
#include <type_traits>
#include <utility>

using namespace std;
using namespace std::chrono;

typedef long long _INT64;
typedef unsigned long long _UINT64;

namespace UTIL{
    template<typename T>
    bool RangeCheck(T& val, T min, T max){
        if constexpr (std::is_same_v<T, string>){
            int nMin = stoi(min);
            int nMax = stoi(max);
            int nlength = val.length();
            if( (nlength<nMin)||(nlength>nMax)){
                return false;
            }
        }
        else{
            if( (val<min)||(val>max)){
                return false;
            }
        }
        return true;
    }

    bool IsAlpha(const std::string& str){
        for (char ch : str) {
            if (!std::isalpha(static_cast<unsigned char>(ch))) {
                return false;
            }
        }
        return true;
    }  

    template<typename T>
    bool Input(T& val, T min, T max){
        cin>>val;
        return RangeCheck(val, min, max);
    }
    std::chrono::high_resolution_clock::time_point g_startTime, g_endTime;

    void StartTimer(){
        g_startTime = high_resolution_clock::now();
    }
    void EndTimer(){
        g_endTime = high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<milliseconds>(g_endTime-g_startTime);
        cout<< "Elapsed: "<< time_span.count()<<"ms"<<endl;
    }
}

class CQuest{
public:
    bool InputData(){
        if(!UTIL::Input(m_number, 0, 1'000'000)){
            return false;
        }
        return true;
    }
    void Process(){
        bool bFind=false;
        int nPrime=m_number;
        while(!bFind){ 
        //다음 소수를 구한다. 
            nPrime = findNextPrime(nPrime);
            if(nPrime ==-1){
                nPrime++;
                continue;
            }
        //해당 소수가 팰린드롬인지 확인한다. 
            if( isPalindrome(nPrime)){
                m_ret = nPrime;
                break;
            }
            nPrime++;
        } 
    }
    void Print(){
        cout<<m_ret<<'\n';
    }
private:
    int m_number;
    int m_ret=0;
    int findNextPrime(int aNum){
        //다음 소수를 찾는다. 
        int ret=-1;
        int i=aNum;
        while(true){
            if(i%2==0){
                if(i==2){
                    //2는 소수이므로 break.
                    ret = i;
                    break;
                }
                //2의 배수는 소수가 아니므로 다음 수를 찾음.
                i++;
                continue;
            }
            if( isPrime(i)){
                ret = i;
                break;
            }
            i++;
        }
        return ret;
    }
    bool isPrime(int aNum){
        if( aNum==1){
            return false;
        }
        int nSqrt = sqrt(aNum);
        int nCnt=0;
        for(int j{3};j<=nSqrt; j+=2){
            if(aNum%j ==0){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(int aNum){
        string strNum = to_string(aNum);
        string revNum = strNum;
        std::reverse(revNum.begin(), revNum.end());
        if( strNum.compare(revNum)==0){
            return true;
        }
        return false;
    }
};

int main()
{
    //UTIL::StartTimer();
    ios::sync_with_stdio(false);
    cin.tie(0);

    CQuest quest;
    if (!quest.InputData()){
        return -1;
    } 
    quest.Process(); 
    quest.Print();
    //UTIL::EndTimer();
    
    return 0;
}