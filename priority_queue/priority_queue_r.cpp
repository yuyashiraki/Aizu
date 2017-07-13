#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string command;
    int key;
    priority_queue<int> PQ;
    while(1) {
        cin >> command;
        if (command == "insert") {
            cin >> key;
            PQ.push(key);
        } else if (command == "extract") {
            cout << PQ.top() << endl;
            PQ.pop();
        } else if (command == "end") {
            break;
        }
    }
    return 0;
}
