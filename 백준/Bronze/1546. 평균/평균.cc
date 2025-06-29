#include <iostream>
#include <ostream>
#include <vector>

using namespace std;
class CSubject
{
private:
    int m_realScore;
    float m_cvtScore;
public:
    void SetRealScore(int &score){
        m_realScore=score;
    }
    int GetRealScore(){
        return m_realScore;
    }
    void CvtScore(const int& maxScore){
        m_cvtScore = (((float)m_realScore)/maxScore)*100;
    }
    float GetCvtSocre(){
        return m_cvtScore;
    }
};
class CAverage
{
private:
    int m_count;
    int m_maxScore;
    float m_average;
    vector<CSubject> m_subject;
    
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

    void getMaxScore(){
        m_maxScore=-1;
        for( auto subject: m_subject){
            int score = subject.GetRealScore();
            if( m_maxScore < score){
                m_maxScore = score;
            }
        }
    }
    void cvtScore()
    {
        for( auto& subject: m_subject){
            subject.CvtScore(m_maxScore);
        }
    }
    void getAverage(){
        float sum=0.0f;
        for( auto subject: m_subject){
            sum += subject.GetCvtSocre();
        }
        m_average = sum/m_subject.size();
    }
public:
    bool InputData(){
        cin >> m_count;
        if( !rangeCheck(m_count, 0, 1000)){
            return false;
        }
        for( int cnt=0; cnt< m_count; ++cnt){
            int number;
            if(!input(number,0,1000))
                return false;
            CSubject subject;
            subject.SetRealScore(number);
            m_subject.push_back(subject);
        }
        return true;
    }

    void Process(){
        getMaxScore();
        cvtScore();
        getAverage();
    }
    void Print(){
       cout<< m_average<<endl;
    }
};

int main()
{
    CAverage average;
    if(!average.InputData()){
        return -1;
    }
    average.Process();
    average.Print();
    return 0;
}