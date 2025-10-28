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
    void SetNode(int n){
        n=n+1;
        m_graph.assign(n, vector<int>(n, 0));
        m_visitor.assign(n, false);
        m_vetex=n;
    }
    void AddEdge(int a, int b){
      m_graph[a][b]=1;
      m_graph[b][a]=1;    
    }
    int GetCount(){
        return m_treeCount;
    }
    void Dfs(int vetex){
        m_visitor[vetex]=true;
        for(int i{0};i<m_vetex; ++i){
            if(!m_visitor[i] && m_graph[vetex][i]==1){
                Dfs(i);
            }
        }
    }
    void StartDfs(){
        for(int i{1}; i<m_vetex; ++i){
            if( m_visitor[i]!=false){
                continue;
            }
            m_treeCount++;
            Dfs(i);
        }
    }
private: 
    int m_vetex;
    vector<vector<int>> m_graph;
    vector<bool> m_visitor;
    int m_treeCount=0;

};
class CQuest{
public:
    bool InputData(){
        if(!UTIL::Input(m_pointCnt, 0, 1'000)){
            return false;
        }
        
        if(!UTIL::Input(m_edgeCnt, 0, m_pointCnt*(m_pointCnt-1)/2)){
            return false;
        }

        for(int i{}; i<m_edgeCnt; ++i){
            int x, y;
            if(!UTIL::Input(x, 0, m_pointCnt)){
                return false;
            }
        
            if(!UTIL::Input(y, 0, m_pointCnt)){
                return false;
            }
            if( x==y){
                return false;
            }
            m_data.insert({x,y});
        }
        return true;
    }
    void Process(){
        m_graph.SetNode(m_pointCnt);
        for(auto edge: m_data){
            m_graph.AddEdge(edge.first, edge.second);
        }

        m_graph.StartDfs();        
    }
    void Print(){
        cout<< m_graph.GetCount()<< "\n";
    }
private:
    int m_edgeCnt=0;
    int m_pointCnt=0;
    CGraph m_graph;
    set<pair<int,int>> m_data;
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