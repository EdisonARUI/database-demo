#pragma once

#include "SQLParser.h"
#include "SQLParserResult.h"
#include "util/sqlhelper.h"
#include "metadata.h"

using namespace hsql;

namespace bydb {

class Parser {
public:
    Parser();
    ~Parser();

    bool parseStatement(std::string query);//入口输入sql语句

    SQLParserResult* getResult() { return result_; }//返回parser解析结果

private:
    //check接口不断校验meta元信息
    bool checkStmtsMeta();

    bool checkMeta(const SQLStatement* stmt);

    bool checkSelectStmt(const SelectStatement* stmt);

    bool checkInsertStmt(const InsertStatement* stmt);

    bool checkUpdateStmt(const UpdateStatement* stmt);

    bool checkDeleteStmt(const DeleteStatement* stmt);

    bool checkCreateStmt(const CreateStatement* stmt);

    bool checkDropStmt(const DropStatement* stmt);

    bool checkCreateIndexStmt(const CreateStatement* stmt);

    bool checkCreateTableStmt(const CreateStatement* stmt);

    Table* getTable(TableRef* table_ref);

    bool checkColumn(Table* table, char* col_name);

    bool checkExpr(Table* table, Expr* expr);

    SQLParserResult* result_;
};

}  // namespace bydb