#include "VectorHeader.h"
#include "vectorImplementation.cpp"
using namespace std;

int main()
{
    mmVector<string> v1;
    v1.PushBack("Test");
    v1.PushBack("finished");
    v1.PushBack("successfully");
    cout << v1 << "\n";

    mmVector<int>v3;
    for(int i=1; i<=10; i++)
    {
        v3.PushBack(i);
    }
    mmVector<int> v2;
    for(int i=1; i<=10; i++)
    {
        v2.PushBack(i);
    }
    
    if(v3==v2){
        cout << "Yes";
    }
    else
    {
        cout << "NO";
    }
}
