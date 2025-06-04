#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "country.h"
#include "database.h"

// 定义一个静态回调函数，打印每一行的查询结果
static int printCallback(void* notUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int addCountry(sqlite3* db, const Country* country) {
    char sql[512];
    snprintf(sql, sizeof(sql),
             "INSERT INTO country (name, capital, language, population_country, square_country, currency, head_country) "
             "VALUES ('%s', '%s', '%s', %d, %f, '%s', '%s');",
             country->name, country->capital, country->language,
             country->population, country->square, country->currency, country->head);
    return executeSQL(db, sql);
}

int updateCountry(sqlite3* db, int id, const Country* country) {
    char sql[512];
    snprintf(sql, sizeof(sql),
             "UPDATE country SET name='%s', capital='%s', language='%s', population_country=%d, square_country=%f, currency='%s', head_country='%s' "
             "WHERE id=%d;",
             country->name, country->capital, country->language,
             country->population, country->square, country->currency, country->head, id);
    return executeSQL(db, sql);
}

int deleteCountry(sqlite3* db, int id) {
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM country WHERE id=%d;", id);
    return executeSQL(db, sql);
}

int queryCountry(sqlite3* db, int id) {
    char* errMsg = NULL;
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM country WHERE id=%d;", id);
    
    int rc = sqlite3_exec(db, sql, printCallback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    return rc;
}

