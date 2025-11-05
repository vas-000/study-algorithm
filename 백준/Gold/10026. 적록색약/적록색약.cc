#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <random>
#include <type_traits>
#include <utility>

using namespace std;
using namespace std::chrono;

typedef long long _INT64;
typedef unsigned long long _UINT64;

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

class CGraph{
public:
    void SetSize(int aWidth, int aHeight){
        m_width = aWidth;
        m_height = aHeight;
        m_graph.assign(aHeight, vector<int>(aWidth, 0));
        m_visitor.assign(aHeight, vector<bool>(aWidth, false));
    }

    void AddRow(const string& aRow, int aHeight){
        for(int i{}; i<m_width; ++i){
            char cell = aRow.at(i);
            if(cell=='R'){
                m_graph[aHeight][i]=1;
            }
            else if(cell=='G'){
                m_graph[aHeight][i]=2;
            }
            else if( cell == 'B'){
                m_graph[aHeight][i]=4;
            }
        }
    }

    void PrintGraph(){
        for(int i=0; i< m_height; ++i){
            for(int j=0; j< m_width; ++j){
                cout<< m_graph[i][j];
            }
            cout << endl;
        }
    }

    int GetCount(){
        return m_treeCount;
    }
    void Dfs(int height, int width, int mask){
        //cout<< "("<<height<<","<<width<<","<< (m_graph[height][width]&mask) << ") ->";
        if( height <0 && height>=m_height){
            return;
        }
        if( width <0 && width >= m_width){
            return;
        }
        
        m_visitor[height][width]=true;
        m_size++;
        
        // ->, V, <- 방향으로 값이 있는지 확인한다. 
        int incW = width+1;
        int decW = width-1;
        int incH = height+1;
        int decH = height-1;
        
        if(decH >=0 && !m_visitor[decH][width] && ((m_graph[decH][width]&mask) >0)){
            Dfs(decH, width, mask);
        }

        if( incW < m_width && !m_visitor[height][incW] && ((m_graph[height][incW]&mask) >0)){
            Dfs(height, incW, mask);
        }

        if( incH<m_height && !m_visitor[incH][width] && ((m_graph[incH][width]&mask)>0)){
            Dfs(incH, width, mask);
        }

        if( decW>=0 && !m_visitor[height][decW] && ((m_graph[height][decW]&mask)>0)){
            Dfs(height, decW, mask);
        }
        
    }
    int Start(int mask){
        clearVistor();
        for(int i{0}; i< m_height; ++i){
            for(int j{0}; j<m_width; ++j){
                if(m_visitor[i][j]!= false || 
                    ((m_graph[i][j]&mask)==0)){
                    continue;
                }
                m_treeCount++;
                Dfs(i, j, mask);
            }
        }
        return m_treeCount;
    }
private: 
    int m_width, m_height;
    vector<vector<int>> m_graph;
    vector<vector<bool>> m_visitor;
    int m_treeCount=0;
    int m_size=0;
    void clearVistor(){
        m_treeCount=0;
         m_visitor.assign(m_height, vector<bool>(m_width, false));
    }

};
class CQuest{
public:
    bool InputData(){
        int nSize;
        if(!UTIL::Input(nSize, 0, 100)){
            return false;
        }
    
        m_graph.SetSize(nSize, nSize);

        for(int i{}; i<nSize; ++i){
            string row;
            cin>>row;
            if(row.length()>nSize){
                return false;
            }
            m_graph.AddRow(row, i);
        }
       
        return true;
    }
    void Process(){
        int r,g,b, rg;
        r = m_graph.Start(1);
        g = m_graph.Start(2);
        b = m_graph.Start(4);
        rg = m_graph.Start(3);
        m_normal = r+g+b;
        m_colorBlindess = rg+b;
    }
    void Print(){
        cout << m_normal<<" "<<m_colorBlindess<<"\n";
    }
private:
    CGraph m_graph;
    int m_normal;
    int m_colorBlindess;
};

int main()
{
    //UTIL::StartTimer();
    ios::sync_with_stdio(false);
    cin.tie(0);

    CQuest quest;
    if (!quest.InputData()){
        return -1;
    } 
    quest.Process(); 
    quest.Print();
    //UTIL::EndTimer();
    
    return 0;
}