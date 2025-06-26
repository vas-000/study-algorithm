#include <iostream>
#include <string>

using namespace std;

class cPalindrome
{
private:
    string m_input;
    string m_revString;
    void reverse(){
        for(int i=m_input.length()-1; i >= 0; --i){
            m_revString.push_back(m_input.at(i));
        }
    }
public:
    void GetInput(){
        cin >> m_input;
    }

    bool Check(){
        reverse();
        if( m_input.compare(m_revString)==0){
            return true;
        }       
        return false;
    }
};
int main()
{
    cPalindrome Palindrome;
    Palindrome.GetInput();
    cout<< Palindrome.Check()<<endl;
}