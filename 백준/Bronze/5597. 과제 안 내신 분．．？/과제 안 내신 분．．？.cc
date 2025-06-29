#include <iostream>
#include <map>
#include <vector>

using namespace std;
class CStudent
{
private:
    bool m_hasWorked=false;
public:
    void SubmitHomeWork(){
        m_hasWorked = true;
    }
    bool IsSubmitHoeWork(){
        return m_hasWorked;
    }
};
class CHomework
{
private:
    map<int, CStudent> m_students;
    vector<int> m_notSubmitted;

    bool rangeCheck(int& val, int min, int max){
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }
    bool input(int& val, int min, int max){
        cin>>val;
        return rangeCheck(val, min, max);
    }
public:
    CHomework(){
        for(int i=1; i<=30; ++i){
            CStudent student;
            m_students[i]=student;
        }
    }
    bool InputData(){
        for( int cnt=0; cnt< 28; ++cnt){
            int id;
            if(!input(id,1,30))
                return false;
            m_students[id].SubmitHomeWork();
        }
        return true;
    }

    void Process(){
        for(int i=1; i<=30; ++i){
            if( m_students[i].IsSubmitHoeWork()==true)
                continue;
            m_notSubmitted.push_back(i);
        }
    }
    void Print(){
       cout << m_notSubmitted[0]<<endl;
       cout << m_notSubmitted[1]<<endl;
    }
};

int main()
{
    CHomework homework;
    if(!homework.InputData()){
        return -1;
    }
    homework.Process();
    homework.Print();
    return 0;
}