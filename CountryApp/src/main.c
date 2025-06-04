#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "country.h"
#include "region.h"

// 打印主菜单的函数 / Function to print the main menu
void printMenu() {
    printf("\n====================================\n");
    printf("         CountryApp 主菜单         \n");
    printf("         CountryApp Main Menu      \n");
    printf("====================================\n");
    printf("1. 添加国家 / Add Country\n");
    printf("2. 删除国家 / Delete Country\n");
    printf("3. 更新国家 / Update Country\n");
    printf("4. 查询国家 / Query Country\n");
    printf("5. 添加地区 / Add Region\n");
    printf("6. 删除地区 / Delete Region\n");
    printf("7. 更新地区 / Update Region\n");
    printf("8. 查询地区 / Query Region\n");
    printf("0. 退出程序 / Exit\n");
    printf("====================================\n");
    printf("请输入操作选项 / Please enter your choice: ");
}

int main() {
    int choice;
    sqlite3 *db;

    // 直接连接数据库（确保项目根目录下存在符合表结构要求的数据库文件 countries.db）
    // Directly connect to the database (ensure that the database file countries.db exists in the project root and meets schema requirements)
    if (connectDatabase("countries.db", &db) != SQLITE_OK) {
        exit(1);
    }
    
    // 显示主菜单循环，直到用户选择退出 / Display the main menu in a loop until the user chooses to exit
    do {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: {  // 添加国家 / Add Country
                Country country;
                printf("请输入国家名称 (Enter Country Name): ");
                scanf("%s", country.name);
                printf("请输入首都 (Enter Capital): ");
                scanf("%s", country.capital);
                printf("请输入使用语言 (Enter Language): ");
                scanf("%s", country.language);
                printf("请输入人口 (Enter Population): ");
                scanf("%d", &country.population);
                printf("请输入国土面积 (Enter Area): ");
                scanf("%f", &country.square);
                printf("请输入货币 (Enter Currency): ");
                scanf("%s", country.currency);
                printf("请输入国家元首 (Enter Head of State): ");
                scanf("%s", country.head);
                if (addCountry(db, &country) == SQLITE_OK) {
                    printf("添加国家成功！ / Country added successfully!\n");
                } else {
                    printf("添加国家失败！ / Failed to add country!\n");
                }
                break;
            }
            case 2: {  // 删除国家 / Delete Country
                int id;
                printf("请输入要删除的国家ID (Enter Country ID to delete): ");
                scanf("%d", &id);
                if (deleteCountry(db, id) == SQLITE_OK) {
                    printf("删除国家成功！ / Country deleted successfully!\n");
                } else {
                    printf("删除国家失败！ / Failed to delete country!\n");
                }
                break;
            }
            case 3: {  // 更新国家 / Update Country
                int id;
                Country country;
                printf("请输入要更新的国家ID (Enter Country ID to update): ");
                scanf("%d", &id);
                printf("请输入新的国家名称 (Enter new Country Name): ");
                scanf("%s", country.name);
                printf("请输入新的首都 (Enter new Capital): ");
                scanf("%s", country.capital);
                printf("请输入新的使用语言 (Enter new Language): ");
                scanf("%s", country.language);
                printf("请输入新的人口数 (Enter new Population): ");
                scanf("%d", &country.population);
                printf("请输入新的国土面积 (Enter new Area): ");
                scanf("%f", &country.square);
                printf("请输入新的货币 (Enter new Currency): ");
                scanf("%s", country.currency);
                printf("请输入新的国家元首 (Enter new Head of State): ");
                scanf("%s", country.head);
                if (updateCountry(db, id, &country) == SQLITE_OK) {
                    printf("更新国家成功！ / Country updated successfully!\n");
                } else {
                    printf("更新国家失败！ / Failed to update country!\n");
                }
                break;
            }
            case 4: {  // 查询国家 / Query Country
                int id;
                printf("请输入要查询的国家ID (Enter Country ID to query): ");
                scanf("%d", &id);
                queryCountry(db, id);
                break;
            }
            case 5: {  // 添加地区 / Add Region
                Region region;
                printf("请输入地区名称 (Enter Region Name): ");
                scanf("%s", region.name);
                printf("请输入地区首府 (Enter Region Capital): ");
                scanf("%s", region.capital_region);
                printf("请输入地区人口 (Enter Region Population): ");
                scanf("%d", &region.population);
                printf("请输入地区面积 (Enter Region Area): ");
                scanf("%f", &region.square);
                printf("请输入所属国家ID (Enter Country ID): ");
                scanf("%d", &region.country_id);
                if (addRegion(db, &region) == SQLITE_OK) {
                    printf("添加地区成功！ / Region added successfully!\n");
                } else {
                    printf("添加地区失败！ / Failed to add region!\n");
                }
                break;
            }
            case 6: {  // 删除地区 / Delete Region
                int id;
                printf("请输入要删除的地区ID (Enter Region ID to delete): ");
                scanf("%d", &id);
                if (deleteRegion(db, id) == SQLITE_OK) {
                    printf("删除地区成功！ / Region deleted successfully!\n");
                } else {
                    printf("删除地区失败！ / Failed to delete region!\n");
                }
                break;
            }
            case 7: {  // 更新地区 / Update Region
                int id;
                Region region;
                printf("请输入要更新的地区ID (Enter Region ID to update): ");
                scanf("%d", &id);
                printf("请输入新的地区名称 (Enter new Region Name): ");
                scanf("%s", region.name);
                printf("请输入新的地区首府 (Enter new Region Capital): ");
                scanf("%s", region.capital_region);
                printf("请输入新的地区人口 (Enter new Region Population): ");
                scanf("%d", &region.population);
                printf("请输入新的地区面积 (Enter new Region Area): ");
                scanf("%f", &region.square);
                printf("请输入新的所属国家ID (Enter new Country ID): ");
                scanf("%d", &region.country_id);
                if (updateRegion(db, id, &region) == SQLITE_OK) {
                    printf("更新地区成功！ / Region updated successfully!\n");
                } else {
                    printf("更新地区失败！ / Failed to update region!\n");
                }
                break;
            }
            case 8: {  // 查询地区 / Query Region
                int id;
                printf("请输入要查询的地区ID (Enter Region ID to query): ");
                scanf("%d", &id);
                queryRegion(db, id);
                break;
            }
            case 0:
                printf("退出程序。 / Exiting program.\n");
                break;
            default:
                printf("无效选项，请重新输入。 / Invalid choice, please try again.\n");
                break;
        }
    } while(choice != 0);
    
    sqlite3_close(db);
    return 0;
}

