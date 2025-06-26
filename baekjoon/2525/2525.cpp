#include <iostream>

using namespace std;

class CClock
{
private:
    int m_hour;
    int m_min;
    int m_alarm;

    int calcMin(){
        int nDiffMin = m_min + m_alarm;
        m_min=nDiffMin % 60;
        return nDiffMin / 60;
    }
    void calcHour(int hour){
        m_hour+= hour;
        m_hour = m_hour%24;
    }
public:
    CClock(int h, int m, int alarm):
    m_hour(h), m_min(m), m_alarm(alarm){}
    void CalcAlarm(){
        int pastHour = calcMin();
        calcHour(pastHour);
        
    }
    void Print(){
        cout<< m_hour << " "<< m_min<<endl;
    }
};

int main()
{
    int h, m, alarm;
    cin >> h >> m;
    cin >> alarm;
    CClock clock(h, m, alarm);
    clock.CalcAlarm();
    clock.Print();
    return 0;
}