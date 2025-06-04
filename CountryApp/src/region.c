#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "region.h"
#include "database.h"

// 定义一个静态回调函数，用于打印查询结果
static int printCallback(void* notUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int addRegion(sqlite3* db, const Region* region) {
    char sql[512];
    snprintf(sql, sizeof(sql),
             "INSERT INTO region (name, capital_region, population_region, square_region, country_id) "
             "VALUES ('%s', '%s', %d, %f, %d);",
             region->name, region->capital_region, region->population, region->square, region->country_id);
    return executeSQL(db, sql);
}

int updateRegion(sqlite3* db, int id, const Region* region) {
    char sql[512];
    snprintf(sql, sizeof(sql),
             "UPDATE region SET name='%s', capital_region='%s', population_region=%d, square_region=%f, country_id=%d "
             "WHERE id=%d;",
             region->name, region->capital_region, region->population, region->square, region->country_id, id);
    return executeSQL(db, sql);
}

int deleteRegion(sqlite3* db, int id) {
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM region WHERE id=%d;", id);
    return executeSQL(db, sql);
}

int queryRegion(sqlite3* db, int id) {
    char* errMsg = NULL;
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM region WHERE id=%d;", id);
    
    int rc = sqlite3_exec(db, sql, printCallback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    return rc;
}

