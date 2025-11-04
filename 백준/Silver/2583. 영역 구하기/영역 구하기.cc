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
    void SetPoint(int aPoint){
        m_pointCnt = aPoint;
    }

    void AddPoint(int a, int b){
        m_graph[b][a]=1;
    }

    void AddRect(int sX, int sY, int eX, int eY){
        for( int i{sX}; i<eX; i++){
            for(int j{sY}; j<eY; j++){
                AddPoint(i, j);
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
    void Dfs(int height, int width){
        //cout<< "("<<height<<","<<width<<") ->";
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
        
        if(decH >=0 && !m_visitor[decH][width] && m_graph[decH][width]==0){
            Dfs(decH, width);
        }

        if( incW < m_width && !m_visitor[height][incW] && m_graph[height][incW]==0){
            Dfs(height, incW);
        }

        if( incH<m_height && !m_visitor[incH][width] && m_graph[incH][width]==0){
            Dfs(incH, width);
        }

        if( decW>=0 && !m_visitor[height][decW] && m_graph[height][decW]==0){
            Dfs(height, decW);
        }
        
    }
    void Start(){
        for(int i{0}; i< m_height; ++i){
            for(int j{0}; j<m_width; ++j){
                if(m_visitor[i][j]!= false || 
                    m_graph[i][j]==1){
                    continue;
                }
                m_treeCount++;
                m_size=0;
                Dfs(i, j);
                m_area.push_back(m_size);
            }
        }
    }
    void PrintSize()
    {
        sort(m_area.begin(), m_area.end());
        for(auto area: m_area){
            cout<< area <<" ";
        }
    }
private: 
    int m_pointCnt;
    int m_width, m_height;
    vector<vector<int>> m_graph;
    vector<vector<bool>> m_visitor;
    vector<int> m_area;
    int m_treeCount=0;
    int m_size=0;

};
class CQuest{
public:
    bool InputData(){
        int width, height, pointCnt;
        if(!UTIL::Input(height, 0, 100)){
            return false;
        }
        
        if(!UTIL::Input(width, 0, 100)){
            return false;
        }

        m_graph.SetSize(width, height);

        if(!UTIL::Input(pointCnt, 0, 100)){
            return false;
        }
        m_graph.SetPoint(pointCnt);

        for(int i{}; i<pointCnt; ++i){
            int sx, sy, ex, ey; 
            if(!UTIL::Input(sx, 0, width)){
                return false;
            }
        
            if(!UTIL::Input(sy, 0, height)){
                return false;
            }

            if(!UTIL::Input(ex, 0, width)){
                return false;
            }
        
            if(!UTIL::Input(ey, 0, height)){
                return false;
            }

            m_graph.AddRect(sx,sy, ex, ey);
        }
       
        return true;
    }
    void Process(){
        m_graph.Start();
        //m_graph.PrintGraph();
    }
    void Print(){
        cout<< m_graph.GetCount()<< "\n";
        m_graph.PrintSize();
    }
private:
    CGraph m_graph;
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