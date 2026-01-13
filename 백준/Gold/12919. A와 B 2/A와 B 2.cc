#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
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
        if(!UTIL::Input<std::string>(m_S, "1", "49")){ //
            return false;
        }

        if(!UTIL::Input<std::string>(m_T, "2", "50")){ //
            return false;
        }
        if( m_S.length() > m_T.length() ){
            return false;
        }
        return true;
    }

    void Process(){
        // 1. 문자열 뒤에 A를 추가한다. 
        // 2. 문자열 뒤에 B를 추가하고 문자열을 뒤집는다.
        std::vector<std::string> buffer; 
        //buffer.push_back(m_S);
        buffer.push_back(m_T);
        int s_size = m_S.length();
        int t_size = m_T.length();
        while( s_size != t_size){
            std::vector<std::string> tmp;
            for(auto str:buffer){
                #if 0
                tmp.push_back(appendA(str));
                tmp.push_back(pushAndReverse(str));
                #endif
                #if 0
                std::string A = appendA(str);
                size_t pos = m_T.find(A);
                if( pos != std::string::npos)
                    tmp.push_back(A);

                std::string B = pushAndReverse(str);
                pos = m_T.find(B);
                if( pos != std::string::npos)
                    tmp.push_back(B);
                #endif
                if( str.back()=='B' ){
                    if(!chkReverseB(str)){
                        continue;
                    }
                    tmp.push_back(reverseAndPop(str));
                }
                else{
                    //끝이 'A'인 경우
                    tmp.push_back(popEnd(str));
                    if(!chkReverseB(str)){
                        //뒤집었는데 'A'인경우
                        continue;
                    }
                    else{
                        //뒤집었을때 'B'인경우
                        tmp.push_back(reverseAndPop(str));
                    }
                }
            }

            if( tmp.empty() ){
                //cout<< "empty"<<endl;
                m_nResult=0;
                return;
            }
            buffer.clear();
            buffer.insert(buffer.end(), tmp.begin(), tmp.end());
            //s_size++;
            t_size--;
        }

        auto it = std::find(buffer.begin(), buffer.end(), m_S);
        if( it == buffer.end()){
            m_nResult=0;
        }
    }

    void Print(){
        cout<< m_nResult << "\n";
    }
private:
    int m_nResult=1;
    std::string m_S;
    std::string m_T;
    std::string appendA(const std::string& ori){
        std::string str = ori;
        str.push_back('A');
        return str;
    }
    std::string pushAndReverse(const std::string& ori){
        std::string str = ori;
        str.push_back('B');
        std::reverse(str.begin(), str.end());
        return str;
    }
    std::string popEnd(std::string ori){
        ori.pop_back();
        //cout<<ori<<endl;
        return ori;
    }
    std::string reverseAndPop(std::string ori){
        std::reverse(ori.begin(), ori.end());
        ori.pop_back();
        //cout<<ori<<endl;
        return ori;
    }
    bool chkReverseB(std::string ori){
        std::reverse(ori.begin(), ori.end());
        return ( ori.back()=='B');
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