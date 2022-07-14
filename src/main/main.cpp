#include <iostream>
#include "parser.h"
#include "executor.h"
#include "optimizer.h"

using namespace std;

using namespace bydb;
using namespace hsql;

static bool ExecStmt(string stmt) {
    Parser parser;
    if (parser.parseStatement(stmt)) {
        return true;
    }

    SQLParserResult* result = parser.getResult();
    Optimizer optimizer;

    for (size_t i = 0; i < result->size(); ++i) {
        const SQLStatement* stmt = result->getStatement(i);
        Plan* plan = optimizer.createPlanTree(stmt);
        if (plan == nullptr) {
            return true;
        }

        Executor executor(plan);
        executor.init();
        if (executor.exec()) {
            return true;
        }
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
