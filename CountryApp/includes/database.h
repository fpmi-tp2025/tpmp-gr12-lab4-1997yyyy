#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

/**
 * 连接到数据库文件
 * @param dbPath 数据库文件路径
 * @param db 指向 sqlite3 对象的指针
 * @return 成功返回 SQLITE_OK，否则返回错误码
 */
int connectDatabase(const char* dbPath, sqlite3** db);

/**
 * 执行给定 SQL 语句
 * @param db 数据库连接
 * @param sql 要执行的 SQL 语句
 * @return 成功返回 SQLITE_OK，否则返回错误码
 */
int executeSQL(sqlite3* db, const char* sql);

#endif

