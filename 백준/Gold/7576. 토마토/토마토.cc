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
        m_grid.assign(m_height, vector<int>(m_width, -1));
        m_visitor.assign(m_height, vector<bool>( m_width, false));
    }
    void SetGridData(int aY, int aX, int aData){
        m_grid[aY][aX] = aData;
        if( aData == 1){
            m_ripen.push_back({aX, aY});
        }
        if( aData == 0){
            m_notRipenTomatoCount++;
        }
    }
    void BFS(queue<pair<int, int>>& data){
        int nQueueSize = data.size();
        bool bActive = false;
        while(nQueueSize>0){
            pair<int, int> node = data.front();
            data.pop();
            if( m_visitor[node.second][node.first]==true){
                nQueueSize--;
                continue;
            }
            bActive = true;
            //cout<< node.first<<" "<<node.second<<";";
            m_visitor[node.second][node.first]=true;
            m_notRipenTomatoCount--;
            //4방향으로 움직인다. 
            int IncX = node.first+1;
            int IncY = node.second+1;
            int DecX = node.first-1;
            int DecY = node.second-1;
            if( (IncY < m_height) && (m_grid[IncY][node.first]==0) && !m_visitor[IncY][node.first] ){
                // Up
                data.push({node.first, IncY});
            }
            if( (IncX < m_width) && (m_grid[node.second][IncX]==0) && !m_visitor[node.second][IncX] ){
                // Right
                data.push({IncX, node.second});
            }
            if( (DecY>=0) && (m_grid[DecY][node.first]==0) && !m_visitor[DecY][node.first]){
                // Down
                data.push({node.first, DecY});
            }
            if( (DecX>=0) && (m_grid[node.second][DecX]==0) && !m_visitor[node.second][DecX]){
                // Left
                data.push({DecX, node.second});
            }
            nQueueSize--;
        }
        //cout<<endl;
        if(bActive == false){
            m_count--;
        }
    }


    int StartBFS(){
        if( m_ripen.empty()){
            // 익은 토마토가 1개도 없을 경우 
            return -1;
        }
        else if( (m_ripen.size()>=1) && (m_notRipenTomatoCount==0)){
            // 모든 토마토가 익었을 경우 
            return 0;
        }
        queue<pair<int, int>> buffer; // x,y 좌표
        for( auto data:m_ripen){
            buffer.push(data);
        }
        m_notRipenTomatoCount+= buffer.size();
        while (!buffer.empty()){
            m_count++;
            BFS(buffer);
        }

        if( m_notRipenTomatoCount !=0 ){
            //cout<<m_notRipenTomatoCount<<endl;
            return -1;
        }
        return m_count;
    } 
private: 
    int m_nodeSize=100'001;
    int m_count=-1; // 시작도 1번으로 인식하기 때문문
    int m_width=0;
    int m_height=0;
    int m_notRipenTomatoCount=0; //안익은 토마토 갯수
    vector<vector<bool>> m_visitor;
    vector<vector<int>> m_grid;
    vector<pair<int, int>> m_ripen; // 익은 토마토 X,Y 좌표


    void clearVisitor(){
    }
};
class CQuest{
public:
    bool InputData(){
        if(!UTIL::Input(m_width, 2, 1'000)){
            return false;
        }

        if(!UTIL::Input(m_height, 2, 1'000)){
            return false;
        }

        m_graph.SetSize(m_width, m_height);

        for(int i{}; i< m_height; ++i){
            for(int j{}; j< m_width; ++j){
                int data;
                if(!UTIL::Input(data, -1, 1)){
                    return false;
                }

                m_graph.SetGridData(i, j, data);
            }
        }
        return true;
    }
    void Process(){
        m_resBFS = m_graph.StartBFS();
    }
    void Print(){
        cout<<m_resBFS<<'\n';
    }
private:
    CGraph m_graph;
    int m_resBFS;
    int m_width=0;
    int m_height=0;
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