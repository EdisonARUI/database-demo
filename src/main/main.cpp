#include <iostream>
#include "parser.h"

using namespace std;

using namespace bydb;
using namespace hsql;

static bool ExecStmt(string stmt) {
    Parser parser;
    if (parser.parseStatement(stmt)) {
        return true;
    }

    return false;
}


int main() {
    cout << "# Welcome to ByteYoung DB!!!" << endl;
    cout << "# Input your query in one line." << endl;
    cout << "# Enter 'exit' to quit this program." << endl;

    string cmd;
    while (true) {
        getline(cin, cmd);
        if (cmd == "exit") {
            break;
        }
        if (ExecStmt(cmd)) {
            cout << "# ERROR: Failed to execute '" << cmd << "'" << endl;
        }
    }

    cout << "# Farewell~~~ " << endl;
    return 0;
}
