#include <stdio.h>
#include "database.h"

int connectDatabase(const char* dbPath, sqlite3** db) {
    int rc = sqlite3_open(dbPath, db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(*db));
        return rc;
    }
    // 开启外键支持
    rc = sqlite3_exec(*db, "PRAGMA foreign_keys = ON;", NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "无法启用外键功能\n");
    }
    return rc;
}

int executeSQL(sqlite3* db, const char* sql) {
    char* errMsg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    return rc;
}

