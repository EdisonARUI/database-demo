# database-demo
## 字节跳动青训营实操项目
### 项目要求
实现一个内存态数据库 ByteYoungDB，能够支持下面操作：
+ Create/Drop Table, Create/Drop Index
+ Insert、Delete、Update、Select
+ 简单的等值匹配条件 where col = XXX
+ 支持简单的事务Commit，Rollback

### 项目分解
+ SQL引擎
  + Parser：查询解析，生产语法树，并进行合法性校验。（词法分析、语法分析、语义分析）
  + Optimizer：根据语法树选择最优执行路径。
  + Executor：基于火山模型的查询执行流程。
+ 事务引擎
  + 事务提交和回滚机制设计。
+ 存储引擎
  + 数据结构设计
  + 索引结构设计

### 项目搭建
使用大型C/C++项目中最常用的CMake工具。CMake是一种跨平台编译工具。CMake主要是编写CMakeLists.txt文件通过cmake命令将CMakeLists.txt文件转化为make所需要的Makefile文件，最后用make命令编译源码生成可执行程序或者库文件。
