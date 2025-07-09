#include <cctype>
#include <cstdio>
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

enum defDirection{
    defLeft=0,
    defDown,
    def45Down,
    def45Up,
};

class CFindFraction{
public:
    bool InputData(){
        if(!UTIL::Input(m_findId, 1, m_total)){
            return false;
        }
       return true;
    }

    void Process(){
        findCell(0,0, m_findId);
        //0base->1base 변경
        m_row+=1;
        m_col+=1;
    }
    void Print(){
        
        cout<< m_row << "/" << m_col <<endl;
    }
    
private:
    const int m_total=1000000000;
    int m_findId;
    int m_row=0;
    int m_col=0; 
    defDirection m_direct = defDirection::defLeft;   

    void findCell(int row, int col, int find){
        --find;
        if( find==0){
            m_row = row;
            m_col = col;
            return;
        }

        switch(m_direct){
            case defDirection::defLeft:
                moveLeft(row, col);
            break;
            case defDirection::def45Down:
                move45Down(row, col);
            break;
            case defDirection::defDown:
                moveDown(row, col);
            break;
            case defDirection::def45Up:
                move45Up(row, col);
            break;
        }
        
        findCell(row, col, find);
    }

    void moveLeft(int& row, int& col){
        col+=1;
        m_direct = defDirection::def45Down;
    }
    void move45Down(int& row, int& col){
        col-=1;
        row+=1;
        if(col==0){
            m_direct = defDirection::defDown;
        }
    }
    void moveDown(int& row, int& col){
        row+=1;
        m_direct = defDirection::def45Up;
    }
    void move45Up(int&row, int& col){
        row-=1;
        col+=1;
        if(row==0){
            m_direct = defDirection::defLeft;
        }
    }
    
};

int main()
{
    CFindFraction findFraction;
    if(!findFraction.InputData()){
        return -1;
    }
    findFraction.Process();
    findFraction.Print();
    return 0;
}