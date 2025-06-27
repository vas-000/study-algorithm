#include <iostream>

using namespace std;

class CClock
{
private:
    int m_hour;
    int m_min;
    int m_alarm;

    bool calcMin(){
        int nDiffMin = m_min - m_alarm;
        bool bChange= false;
        if( nDiffMin >= 0){
            m_min= nDiffMin;
        }
        else{
            m_min = 60+nDiffMin;
            bChange = true;
        }
        return bChange;
    }
    void calcHour(){
        int nDiffHour=m_hour-1;
        if( nDiffHour < 0){
            m_hour= 23;
        }
        else{
            m_hour = nDiffHour;
        }
    }
public:
    CClock(int h, int m, int alarm):
    m_hour(h), m_min(m), m_alarm(alarm){}
    void CalcAlarm(){
        if( calcMin()){
            calcHour();
        }
    }
    void Print(){
        cout<< m_hour << " "<< m_min<<endl;
    }
};

int main()
{
    int h, m;
    cin >> h >> m;
    CClock clock(h, m, 45);
    clock.CalcAlarm();
    clock.Print();
    return 0;
}