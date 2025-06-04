#ifndef COUNTRY_H
#define COUNTRY_H

#include <sqlite3.h>

typedef struct {
    int id;
    char name[100];
    char capital[100];
    char language[50];
    int population;
    float square;
    char currency[10];
    char head[100];
} Country;

/**
 * 添加一个国家到数据库
 * @param db 数据库连接
 * @param country 指向 Country 结构的指针
 * @return 执行结果
 */
int addCountry(sqlite3* db, const Country* country);

/**
 * 更新指定ID的国家信息
 * @param db 数据库连接
 * @param id 国家ID
 * @param country 新数据
 * @return 执行结果
 */
int updateCountry(sqlite3* db, int id, const Country* country);

/**
 * 删除指定ID的国家
 * @param db 数据库连接
 * @param id 国家ID
 * @return 执行结果
 */
int deleteCountry(sqlite3* db, int id);

/**
 * 查询指定ID的国家，并输出相关信息
 * @param db 数据库连接
 * @param id 国家ID
 * @return 执行结果
 */
int queryCountry(sqlite3* db, int id);

#endif

