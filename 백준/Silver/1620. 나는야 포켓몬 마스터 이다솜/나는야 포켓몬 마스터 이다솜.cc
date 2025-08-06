#include <cctype>
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>

//자료형
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

//알고리즘
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

#define TESTCASE 0

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

class CPocketMon{
public:
    bool InputData(){
        int count;
        if(!UTIL::Input<int>(count, 1, 100'000)){
            return false;
        }
        
        int correctCount;
        if(!UTIL::Input<int>(correctCount, 1, 100'000)){
            return false;
        }

        if(!getPocketmonData(count)){
            return false;
        }

        if(!getQuestionData(correctCount, count)){
            return false;
        }
        return true;
    }
    void Process(){
        for(auto data: m_question){
            if(data.nType == defNum){
                auto ret = m_indexToString.find(data.nData);
                m_correct.push_back(ret->second);
            }
            else if( data.nType ==defString){
                auto ret = m_stringToIndex.find(data.strData);
                m_correct.push_back(to_string(ret->second));
            }
        }
    }
    void Print(){
        for(auto data: m_correct){
            cout<<data<<'\n';
        }
    }
private:
    map<string, int> m_stringToIndex;
    map<int, string> m_indexToString;
    enum{
        defNum=0,
        defString
    };
    typedef struct ST_QDATA{
        int nType;
        string strData;
        int nData;
    }stQData;
    vector<stQData> m_question;
    vector<string> m_correct;

    bool getPocketmonData(int count){
        // PocketMonName map.
        for(int i{1}; i<= count; ++i){
            string name;
            if(!UTIL::Input<string>(name, "2", "20")){
                return false;
            }
            m_stringToIndex[name]=i;
            m_indexToString[i]=name;
        }
        return true;
    }

    bool getQuestionData(int questionCount, int totalPocketmon){
        //correct
        for( int i{}; i<questionCount; ++i){
            string data;
            if(!UTIL::Input<string>(data, "1", "20")){
                return false;
            }
            // 숫자인지 문자인지 판별
            // 숫자이면 1~totalPocketmon까지 인지 판별
            // 문자이면 추가
            stQData qData;
            try{
                int num = stoi(data);
                if( (num<1) || (num>totalPocketmon)){
                    return false;
                }   
                qData.nType = defNum;
                qData.nData = num;
            }
            catch(const std::invalid_argument& e){
                //변환 실패면 문자열임.
                //다른 처리 없음. ㅋㅋ
                qData.nType = defString;
                qData.strData = data;
            }
            m_question.push_back(qData);
        }
        return true;
    }
};

int main()
{
    //UTIL::StartTimer();
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    CPocketMon pocketmon;
    if (!pocketmon.InputData()){
        return -1;
    } 
    pocketmon.Process(); 
    pocketmon.Print();
    //UTIL::EndTimer();
    
    return 0;
}