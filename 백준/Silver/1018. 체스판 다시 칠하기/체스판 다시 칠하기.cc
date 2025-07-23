#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

namespace UTIL{
    template<typename T>
    bool RangeCheck(T& val, T min, T max){
        if( (val<min)||(val>max)){
            return false;
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

class CBoard{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_row, 8, 50)){
            return false;
        }
        if(!UTIL::Input<int>(m_col, 8, 50)){
            return false;
        }
        if( !inputBoardData()){
            return false;
        }
        return true;
    }
    void Process(){ 

        vector<int> nChangeCnt;
         for(int i=0; i<=m_row-m_sel; ++i){
            for(int j=0; j<=m_col-m_sel; ++j){
                nChangeCnt.push_back(chkRect(i, j, 0));
                nChangeCnt.push_back(chkRect(i, j, 1));
            }
         }

         m_minCnt = *min_element(nChangeCnt.begin(), nChangeCnt.end());
    }
    void Print(){
        cout<< m_minCnt <<endl;
    }
private:
    int m_row, m_col;
    int m_minCnt;
    static const int m_sel = 8;
    char m_bestMap[2][m_sel][m_sel]={
        {
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'}
        },{
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'},
            {'B','W','B','W','B','W','B','W'},
            {'W','B','W','B','W','B','W','B'}
        }
    };
    vector<vector<char>> m_board;

    bool inputBoardData(){
        for(int i=0; i<m_row; ++i){
            vector<char> row;
            for(int j=0; j< m_col; ++j){
                char data;
                cin>>data;
                if( data == 'W' || data == 'B')
                    row.push_back(data);
                else
                    return false;
            }
            m_board.push_back(row);
        }
        return true;
    }

    int chkRect(int x, int y, int type){
        int nCount=0;
        for( int i=0; i< 8; ++i){
            for( int j=0; j<8; ++j){
                if( m_board[x+i][y+j]-m_bestMap[type][i][j]!=0)
                    nCount++;
            }
        }
        return nCount;
    }
};

int main()
{
    CBoard board;
    if (!board.InputData()){
        return -1;
    } 
    board.Process(); 
    board.Print();
    return 0;
}