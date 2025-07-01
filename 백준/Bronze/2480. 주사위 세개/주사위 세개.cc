#include <iostream>
#include <vector>

using namespace std;

class CDice
{
private:
    int nValue;
    vector<int> sameValueDices;
public:
    CDice(int value):nValue(value){}

};

class CDiceGame
{
private:
    const int g_diceCount=3;
    vector<int> m_dices;
    int m_diceValue=-1;
    int m_prize;

    int compareDice(int first, int second){
        int val1 = m_dices.at(first);
        int val2 = m_dices.at(second);
        if(val1 > val2){
            return 1;
        }
        else if(val1<val2){
            return -1;
        }
        
        return 0;
    }
    int compareDices(){
      int a = compareDice(0, 1);
      int b = compareDice(0, 2);
      int c = compareDice( 1, 2);

      if( (a==0) && (b==0) && (c==0)){
        m_diceValue = m_dices.at(0);
        return 1;
      }
      else if( (a!=0)&& (b!=0) && (c!=0)){
        for(auto val:m_dices){
            if(m_diceValue < val){
                m_diceValue=val;
            }
        }
        return -1;
      }
      else{
        if(a==0){
            m_diceValue = m_dices.at(0);
        }
        else if(b==0){
            m_diceValue = m_dices.at(0);
        }
        else if(c==0){
            m_diceValue = m_dices.at(1);
        }
        return 0;
      }
        return -1;
    }

    int getDiceValue(){
        return m_diceValue;
    }
    void setDiceValue(int value){
        if( value > m_diceValue )
            m_diceValue = value;
    }
public:
    CDiceGame(){
        m_dices.resize(g_diceCount);
    }
    void InputDiceValue(){
        cin>> m_dices[0] >> m_dices[1] >> m_dices[2];
    }

    void CalcPrize(){
        int nType = compareDices();
        if( nType == 1){
            m_prize= 10000+ (getDiceValue()*1000);
        }
        else if( nType == -1){
            m_prize = getDiceValue()*100;
        }
        else{
            m_prize=1000+ (getDiceValue()*100);
        }
    }

    void PrintPrize(){
        cout<< m_prize<<endl;
    }
};

int main()
{
    CDiceGame game;
    game.InputDiceValue();
    game.CalcPrize();
    game.PrintPrize();
    return 0;
}