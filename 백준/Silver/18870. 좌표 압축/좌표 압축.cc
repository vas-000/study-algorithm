#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long _INT64;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<_INT64> m_data;
  
  int nCase;
  cin>> nCase;
  if((nCase<1)||(nCase>1'000'000) ){
    return -1;
  }

  while( nCase>0){
    _INT64 data;
    cin>> data;
    if( (data<-1'000'000'000)||(data>1'000'000'000)){
        cout<<"error:"<< data <<endl;
      return -1;
    }
    m_data.push_back(data);
    nCase--;
 }

 set<_INT64> calc;
 for(auto data:m_data){
  calc.insert(data);
 }

 map<_INT64, int> posData;
 int i=0;
 for(auto data: calc){
   posData[data]=i++;
 }

 for(auto data:m_data){
  cout<< posData[data]<< ' ';
 }
 cout <<'\n';
  return 0;
}
