#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int nCase;
  cin>> nCase;
  if((nCase<1)||(nCase>10'000'000) ){
    return -1;
  }

  int arrCount[10'001]={0,};
  
  int data;
  while( nCase>0){
    cin>> data;
    if( (data<0)||(data>10'000)){
      return -1;
    }
    arrCount[data]++;
    nCase--;
  }

  for( int i=0; i< 10'001; ++i){
    for(int j=0; j< arrCount[i]; ++j){
      cout<< i<<'\n';
    }
  }
  return 0;
}