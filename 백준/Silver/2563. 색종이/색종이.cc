#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

namespace UTIL{
    bool RangeCheck(int& val, int min, int max){
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }

    bool Input(int& val, int min, int max){
        cin>>val;
        return RangeCheck(val, min, max);
    }
}
class CColoredPaper
{
private:
    int m_x, m_y;
    int m_maxX, m_maxY;
public:
    bool InputData(){
        cin >> m_x >> m_y;
        if( !UTIL::RangeCheck(m_x, 0, 90) ||
            !UTIL::RangeCheck(m_y, 0, 90)){
            return false;
        }
        m_maxX = m_x+10;
        m_maxY = m_y+10;
        return true;
    }
    void GetMinMaxPoint(int& x, int& y, int& maxX, int& maxY){
        if( x > m_x || x==-1){
            x= m_x;
        }
        if(y > m_y|| y==-1){
            y=m_y;
        }
        if(maxX< m_maxX){
            maxX=m_maxX;
        }
        if(maxY<m_maxY){
            maxY=m_maxY;
        }
    }
    void SetBase(const int& x, const int& y){
        m_x-=x;
        m_y-=y;
        m_maxX=m_x+10;
        m_maxY=m_y+10;
    }
    void SetFill(vector<vector<char>>& area){
        for(int j=m_y; j< m_maxY; ++j){
            for( int i=m_x; i<m_maxX; ++i){
                area[j][i]=1;
            }
        }
    }
};

class CArea{
public:
    bool InputData(){
       if(!UTIL::Input(m_count, 0, 100)){
        return false;
       }

       for(int i=0; i< m_count; ++i){
            CColoredPaper paper;
            if( !paper.InputData()){
                return false;
            }
            m_coloredPaper.push_back(paper);
       }
       return true;
    }

    void Process(){
        //색종이가 붙은 최대 영역을 구한다. 
        int x=-1, y=-1, maxX=0, maxY=0;
        for(auto paper:m_coloredPaper ){
            paper.GetMinMaxPoint(x, y, maxX, maxY);
        }
        for( int i=y; i<maxY; ++i){
            vector<char> row;
            for(int j=x; j<maxX; ++j){
                char ch=0;
                row.push_back(ch);
            }
            m_area.push_back(row);
        }

        for(auto paper:m_coloredPaper ){
            paper.SetBase(x, y);
            paper.SetFill(m_area);
        }

    }
    void Print(){
        for(auto row: m_area){
            for(auto col: row){
                if( col==1){
                    m_totalArea+=1;
                }
            }
        }

        cout << m_totalArea<<endl;
    }
    
private:
    int m_count;
    int m_totalArea=0;
    vector<vector<char>> m_area;
    vector<CColoredPaper> m_coloredPaper;
};

int main()
{
    CArea area;
    if(!area.InputData()){
        return -1;
    }
    area.Process();
    area.Print();
    return 0;
}