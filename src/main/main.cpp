#include <iostream>

using namespace std;

int main() {
    cout << "# Welcome to ByteYoung DB!!!" << endl;
    cout << "# Input your query in one line." << endl;
    cout << "# Enter 'exit' to quit this program." << endl;

    string cmd;
    while (true) {
        std::getline(std::cin, cmd);
        if (cmd == "exit") {
            break;
        }
    }

    cout << "# Farewell~~~ " << std::endl;
    return 0;
}
