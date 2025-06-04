#ifndef REGION_H
#define REGION_H

#include <sqlite3.h>

typedef struct {
    int id;
    char name[100];
    char capital_region[100];
    int population;
    float square;
    int country_id; // 外键：指向 country 表的 id
} Region;

/**
 * 添加一个地区到数据库
 * @param db 数据库连接
 * @param region 指向 Region 结构的指针
 * @return 执行结果
 */
int addRegion(sqlite3* db, const Region* region);

/**
 * 更新指定ID的地区信息
 * @param db 数据库连接
 * @param id 地区ID
 * @param region 新数据
 * @return 执行结果
 */
int updateRegion(sqlite3* db, int id, const Region* region);

/**
 * 删除指定ID的地区
 * @param db 数据库连接
 * @param id 地区ID
 * @return 执行结果
 */
int deleteRegion(sqlite3* db, int id);

/**
 * 查询指定ID的地区，并输出相关信息
 * @param db 数据库连接
 * @param id 地区ID
 * @return 执行结果
 */
int queryRegion(sqlite3* db, int id);

#endif

