#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << "Elements present in the unordered set: ";
    for (auto &m : s) {
        cout << m << " ";
    }
    cout << endl;

}