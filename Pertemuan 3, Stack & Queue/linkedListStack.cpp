#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s;
    int input;

 //input berhenti ketika input bukan angka
    while (cin >> input)
    {
        s.push(input);
    }

    //Mengeluarkan dan menampilkan semua data
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
    
    
}
