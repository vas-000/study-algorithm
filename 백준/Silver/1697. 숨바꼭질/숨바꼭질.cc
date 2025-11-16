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
    void SetNodes(int aStart, int aEnd){
        m_startNode = aStart;
        m_endNode = aEnd;
    }

    void BFS(queue<int>& data){
        int bFind = false;
        int nQueueSize = data.size();
        while(nQueueSize>0){
            int node = data.front();
            data.pop();
            if( m_visitor[node]==true){
                nQueueSize--;
                continue;
            }
            if( node == m_endNode){
                // success.
                bFind = true;
                break;
            }
            
            //cout<< node<<" ";
            m_visitor[node]=true;
            
            int next = node+1;
            int pre = node-1;
            int teleporting = node*2;
            if( next<= 100'000 && !m_visitor[next] ){
                data.push(next);
            }
            if( pre>=0 && !m_visitor[pre] ){
                data.push(pre);
            }
            if( teleporting<=100'000 && !m_visitor[teleporting]){
                data.push(teleporting);
            }
            nQueueSize--;
        }

        //cout<<endl;
        if( bFind == true){
            while(!data.empty()){
                data.pop();
            }
            return;
        }
    }


    int StartBFS(){
        if( m_startNode < m_endNode){
            clearVisitor();
            queue<int> buffer;
            buffer.push(m_startNode);
            while (!buffer.empty()){
                m_count++;
                BFS(buffer);
            }
            return m_count;
        }
        else{
            return m_startNode-m_endNode;
        }
    } 
private: 
    int m_nodeSize=100'001;
    int m_count=-1; // 시작도 1번으로 인식하기 때문문
    int m_startNode;
    int m_endNode;
    vector<bool> m_visitor;

    void clearVisitor(){
        m_visitor.resize(0);
        m_visitor.assign(m_nodeSize, false);
    }
};
class CQuest{
public:
    bool InputData(){
        if(!UTIL::Input(m_posSubin, 0, 100'000)){
            return false;
        }

        if(!UTIL::Input(m_posBrother, 0, 100'000)){
            return false;
        }

        m_graph.SetNodes(m_posSubin, m_posBrother);
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
    int m_posSubin=0;
    int m_posBrother=0;
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