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
    void SetGraphData(int aNodes, int aStartNode){
        m_nodeSize = aNodes;
        m_startNode = aStartNode;
        m_table.assign(m_nodeSize, vector(m_nodeSize,0));
        m_visitor.assign(aNodes, false);
    }

    void AddEdge(int aStart, int aEnd){
        int x = aStart-1;
        int y = aEnd-1;
        m_table[x][y]=1;
        m_table[y][x]=1;
    
    }

    void DFS(vector<int>& aOut, int aNode){
        m_visitor[aNode]=true;
        aOut.push_back(aNode+1);
        for(int i{}; i< m_nodeSize; ++i){
            if( !m_visitor[i] && m_table[aNode][i]==1){
                DFS(aOut, i);
            }
        }
    }

    vector<int> StartDFS(){
        vector<int> ret;
        clearVisitor();
        DFS( ret, m_startNode-1);

        //for(auto out: ret){
        //    cout<< out<<" ";
        //}
        //cout <<endl;
        return ret;
    }

    void BFS(vector<int>& aOut, int aNode){
        queue<int> buffer;
        buffer.push(aNode);
        m_visitor[aNode]=true;
        aOut.push_back(aNode+1);
        while(!buffer.empty()){
            int node = buffer.front();
            buffer.pop();    
            for(int i=0; i<m_nodeSize; i++){
                if( !m_visitor[i] && m_table[node][i]==1 ){
                    buffer.push(i);
                    m_visitor[i]=true;
                    aOut.push_back(i+1);
                }
            }
        }
    }

    vector<int> StartBFS(){
        vector<int> ret;
        clearVisitor();
        BFS(ret, m_startNode-1);
        return ret;
    } 
private: 
    int m_nodeSize;
    int m_startNode;
    vector<vector<int>> m_table; // edge table
    vector<bool> m_visitor;

    void clearVisitor(){
        m_visitor.resize(0);
        m_visitor.assign(m_nodeSize, false);
    }
};
class CQuest{
public:
    bool InputData(){
        int nVertex, nEdge, nStart;
        if(!UTIL::Input(nVertex, 1, 1'000)){
            return false;
        }

        if(!UTIL::Input(nEdge, 1, 10'000)){
            return false;
        }

        if(!UTIL::Input(nStart, 1, nVertex+1)){
            return false;
        }

        m_graph.SetGraphData(nVertex, nStart);
        for(int i{}; i<nEdge; ++i){
            int x, y;
            if(!UTIL::Input(x, 1, nVertex+1)){
                return false;
            }

            if(!UTIL::Input(y, 1, nVertex+1)){
                return false;
            }
            m_graph.AddEdge(x,y);
        }
        return true;
    }
    void Process(){
        m_resDFS = m_graph.StartDFS();
        m_resBFS = m_graph.StartBFS();
    }
    void PrintData(vector<int>& data){
        for(auto val:data){
            cout<< val << " ";
        }
        cout<<'\n';
    }
    void Print(){
        PrintData(m_resDFS);
        PrintData(m_resBFS);
    }
private:
    CGraph m_graph;
    vector<int> m_resDFS;
    vector<int> m_resBFS;
    int m_count;
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