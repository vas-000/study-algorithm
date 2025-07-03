#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class CSubject{
public:
    bool InputData(){
        cin.precision(1);
        cin>> m_subjectName>>m_creditsEarned>>m_grades;

        if(!chkSubjectName()){
            return false;
        }
        if(!chkCreditsEarned()){
            return false;
        }
        if(!chkGrades()){
            return false;
        }
        return true;
    }
    bool IsSubjectNormal(){
        if( (m_grades.compare("P")==0)){
            return false;
        }
        return true;
    }
    float GetCreditsEarned(){
        return m_creditsEarned;
    }
    float GetGrades(){
        return m_creditsEarned*m_cvtGrades;
    }
private:
    const vector<float> m_creditsEarnedData={1.0,2.0,3.0,4.0};
    const map<string, float> m_gradesData={{"A+",4.5},{"A0",4.0}, {"B+", 3.5}, {"B0", 3.0},
                                    {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5},{"D0", 1.0},
                                    {"F", 0.0}, {"P", 0.0}};
    string m_subjectName;
    float m_creditsEarned;
    string m_grades;
    float m_cvtGrades;

    bool chkSubjectName(){
        if( (m_subjectName.length() > 50) || 
            (m_subjectName.length()<1)){
            return false;
        }
        return true;
    }
    bool chkCreditsEarned(){
        for(int i=0;i<m_creditsEarnedData.size();++i){
            if(m_creditsEarned==m_creditsEarnedData.at(i))
                return true;
        }
        return false;
    }
    bool chkGrades(){
        for(auto grade:m_gradesData){
            if(m_grades.compare(grade.first)==0){
                m_cvtGrades= grade.second;
                return true;
            }
        }
        return false;
    }

};

class CReportCard
{
private:
    float m_average;
    vector<CSubject> m_subjects;
    

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
    bool InputData(){
       for(int i=0; i<20; ++i){
            CSubject subject;
            if(!subject.InputData()){
                if( cin.eof()){
                    return true;
                }  
                return false;
            }
            if( subject.IsSubjectNormal())
                m_subjects.push_back(subject);
        }
        return true;
    }
    void Process(){
        float fTotal=0.0f;
        float fTotalGrades=0.0f;
        for(auto subject:m_subjects){
            fTotal += subject.GetCreditsEarned();
            fTotalGrades += subject.GetGrades();
        }
        if( fTotal==0.0f ){
            m_average = 0.0f;
            return;
        }
        //cout<< fTotal << ", "<< fTotalGrades<<endl;
        m_average = fTotalGrades / fTotal;
    }
    void Print(){
        cout.precision(6);
        cout<<fixed<< m_average<<endl;
    }
};

int main()
{
    CReportCard reportCard;
    if(!reportCard.InputData()){
        return -1;
    }
    reportCard.Process();
    reportCard.Print();
    return 0;
}