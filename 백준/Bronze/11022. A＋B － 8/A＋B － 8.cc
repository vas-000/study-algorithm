#include <iostream>
#include <vector>

using namespace std;
class CTestCase{
    int m_id;
    int m_first;
    int m_second;
public:
    CTestCase(int id, int a, int b)
        :m_id(id), m_first(a), m_second(b){}
    void Print(){
        cout<<"Case #"<<m_id<<": "
            <<m_first<<" + "<<m_second
            <<" = "<<m_first+m_second<<endl;
    }
};
class CTestCases
{
public:
    void InputTestCaseCount(){
        cin >> m_testCaseCount;
    }
    void InputData(){
        int a, b;
        for(int i=1; i<= m_testCaseCount; ++i){
            cin >> a >> b;
            CTestCase testcase(i, a, b);
            m_testcases.push_back(testcase);
        }
    }
    void Print(){
        for(auto testcase:m_testcases){
            testcase.Print();
        }
    }
private:
    int m_testCaseCount;
    std::vector<CTestCase> m_testcases;
};

int main()
{
    CTestCases testcases;
    testcases.InputTestCaseCount();
    testcases.InputData();
    testcases.Print();
    return 0;
}