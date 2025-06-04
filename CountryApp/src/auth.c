#include <string.h>
#include "auth.h"

int authenticate(const char* username, const char* password) {
    // 演示用：固定用户名和密码为 "admin" / "admin123"
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        return 1;  // 认证成功
    }
    return 0;  // 认证失败
}

