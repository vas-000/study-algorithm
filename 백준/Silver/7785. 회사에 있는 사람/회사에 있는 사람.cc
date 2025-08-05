#include <cctype>
#include <chrono>
#include <iostream>
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

class CPerson{
public:
    bool InputData(){
        int count;
        if(!UTIL::Input<int>(count, 2, 1'000'000)){
            return false;
        }
        cin.ignore(); //cin 사용시 '\n'이 남아있어서 문제가 됨.
        // 기록
        for(int i=0; i< count; ++i){
            string row;
            string name; // 사람이름은 5글자 이하, 알파벳 대소문자가 다를경우 다른이름임
            string log; // 출퇴근 기록은 enter, leave
            getline(cin, row);
            size_t pos = row.find(' ');
            name = row.substr(0, pos);
            log = row.erase(0, pos+1);
            if( name.length() > 5){
                return false;
            }
            if( log != "enter" && log != "leave"){
                return false;
            }
            if( m_data.find(name)== m_data.end()){
                m_data[name]=log;
                continue;
            }
            m_data[name]=log;
        }
        return true;
    }
    void Process(){
        for(auto data: m_data){
            if( data.second == "enter"){
                m_person.insert(data.first);
            }
        }
    }
    void Print(){
        for(auto it = m_person.crbegin(); it!= m_person.crend(); ++it){
            cout<< *it<<'\n';
        }
    }
private:
    set<string> m_person;
    map<string, string> m_data;
};

int main()
{
    //UTIL::StartTimer();
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    CPerson person;
    if (!person.InputData()){
        return -1;
    } 
    person.Process(); 
    person.Print();
    //UTIL::EndTimer();
    
    return 0;
}