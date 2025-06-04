# 指定编译器
CC = gcc

# 编译选项和头文件搜索路径
CFLAGS = -Wall -Iincludes

# 链接 SQLite3 库（确保已安装 sqlite3 开发库，可通过 Homebrew 安装：brew install sqlite3）
LIBS = -lsqlite3

# 获取 src/ 文件夹下的所有 .c 源文件
SRC = $(wildcard src/*.c)

# 定义中间文件夹和目标输出文件夹
OBJ_DIR = build
BIN_DIR = bin

# 指定生成的可执行文件名称（生成在 bin/ 文件夹下）
TARGET = $(BIN_DIR)/CountryApp

# 默认目标：生成可执行文件
all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# 清理生成的中间文件和可执行文件
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

