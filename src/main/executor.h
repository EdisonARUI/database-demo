#pragma once

namespace bydb {

class BaseOperator {

};

class CreateOperator : public BaseOperator {

};

class DropOperator : public BaseOperator {

};

class InsertOperator : public BaseOperator {

};

class UpdateOperator : public BaseOperator {

};

class DeleteOperator : public BaseOperator {

};

class TrxOperator : public BaseOperator {

};

class ShowOperator : public BaseOperator {

};

class SelectOperator : public BaseOperator {

};

class SeqScanOperator : public BaseOperator {

};

class FilterOperator : public BaseOperator {

};

class Executor {

};

}  // namespace bydb