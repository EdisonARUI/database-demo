#include "SQLParser.h"
#include "SQLParserResult.h"
#include "util/sqlhelper.h"

#include <string>

using namespace hsql;
using namespace std;

int main(int argc, char* argv[]) {
    argv[1]= "show columns db.t";
//    printf("%s",argv[1]);
    string query = argv[1];

    // parse a given query
    SQLParserResult result;
    SQLParser::parse(query, &result);

    if (result.isValid()) {
        printf("Parsed successfully!\n");
        printf("Number of statements: %lu\n", result.size());

        for (auto i = 0u; i < result.size(); ++i) {
            // Print a statement summary.
            printStatementInfo(result.getStatement(i));
        }
        return 0;
    } else {
        fprintf(stderr, "Given string is not a valid SQL query.\n");
        fprintf(stderr, "%s (L%d:%d)\n",
                result.errorMsg(),
                result.errorLine(),
                result.errorColumn());
        return -1;
    }
    return 0;
}

