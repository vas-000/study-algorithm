#include <iostream>
#include <cstdint>

using namespace std;


int GetLackCount(int ori, int my){
    return ori-my;
}

int main()
{  
    const int chesePiceSize = 6; 
    int chesePice[chesePiceSize]={1, 1, 2, 2, 2, 8};
    int userChesePice[chesePiceSize]={0,};
    
    cin>>userChesePice[0]>>userChesePice[1]>>userChesePice[2]>>userChesePice[3]>>userChesePice[4]>>userChesePice[5];

    for( int i=0; i< chesePiceSize; ++i){
    	cout << GetLackCount(chesePice[i], userChesePice[i])<< " ";
    }

    return 0;
}