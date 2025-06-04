#ifndef AUTH_H
#define AUTH_H

/**
 * 认证用户
 * @param username 用户名
 * @param password 密码
 * @return 认证成功返回1，否则返回0
 */
int authenticate(const char* username, const char* password);

#endif

