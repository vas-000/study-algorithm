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
        m_nodes.insert({b,a});
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
        
        // ->, V, <- 방향으로 값이 있는지 확인한다. 
        int incW = width+1;
        int decW = width-1;
        int incH = height+1;
        int decH = height-1;
        
        if(decH >=0 && !m_visitor[decH][width] && m_graph[decH][width]==1){
            Dfs(decH, width);
        }

        if( incW < m_width && !m_visitor[height][incW] && m_graph[height][incW]==1){
            Dfs(height, incW);
        }

        if( incH<m_height && !m_visitor[incH][width] && m_graph[incH][width]==1){
            Dfs(incH, width);
        }

        if( decW>=0 && !m_visitor[height][decW] && m_graph[height][decW]==1){
            Dfs(height, decW);
        }
        
    }
    void Start(){
        for(auto node: m_nodes){
            int h = node.first;
            int w = node.second;
            //cout << h<<", "<< w<<endl;
            if(m_visitor[h][w]!= false){
                continue;
            }
            m_treeCount++;
            Dfs(h, w);
        
        }
    }
private: 
    int m_pointCnt;
    int m_width, m_height;
    vector<vector<int>> m_graph;
    vector<vector<bool>> m_visitor;
    set<pair<int, int>> m_nodes;
    int m_treeCount=0;

};
class CQuest{
public:
    bool InputData(){
        int nGraphCnt=0;
        cin>>nGraphCnt; // 테스트 케이스에 대한 범위가 존재하지 않음. 
        
        for(int i{}; i< nGraphCnt; i++){
            CGraph graph;
            int width, height, cabbageCnt;
            if(!UTIL::Input(width, 0, 50)){
                return false;
            }
            
            if(!UTIL::Input(height, 0, 50)){
                return false;
            }
            graph.SetSize(width, height);

            if(!UTIL::Input(cabbageCnt, 0, 2'500)){
                return false;
            }
            graph.SetPoint(cabbageCnt);

            for(int i{}; i<cabbageCnt; ++i){
                int x, y; // 배추의 좌표
                if(!UTIL::Input(x, 0, width-1)){
                    return false;
                }
            
                if(!UTIL::Input(y, 0, height-1)){
                    return false;
                }
                graph.AddPoint(x,y);
            }
            m_data.push_back(graph);
        }
        return true;
    }
    void Process(){
        for(auto &graph: m_data){
            graph.Start();
        }
    }
    void Print(){
        for(auto graph: m_data){
            cout<< graph.GetCount()<< "\n";
        }

    }
private:
    vector<CGraph> m_data;
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