# Student Manager —— 一个教学级 C 语言低耦合单链表项目

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Standard](https://img.shields.io/badge/C99-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-blue)](https://github.com/yourname/student-manager)

---

## 🔍 项目简介

Student Manager 用 **单向链表** 实现“学生成绩”增删查排序，代码量不足 500 行，却被拆成 **5 个模块**：

| 模块 | 职责 | 耦合关系 |
|---|---|---|
| `list` | 通用链表（`void *`） | 不依赖任何业务 |
| `student` | 学生结构体 + 业务规则 | 不依赖链表 |
| `ui` | 终端交互 | 只调用 list/student 的 **公开接口** |
| `main` | 启动器 | 只知道 ui |

因此你可以：

- 5 分钟把链表换成动态数组  
- 10 分钟把终端换成 Qt / WebAssembly  
- 15 分钟把“学生”换成“图书”、“商品”——**无需改动底层 list**

---

##  快速开始

### 1. 克隆

```bash
git clone https://github.com/yourname/student-manager.git
cd student-manager
```

## 2. 一键编译

| 方式 | 命令 |
|---|---|
| **CMake**（推荐） | `mkdir build && cd build && cmake .. && cmake --build .` |
| **裸 GCC** | `gcc src/*.c -I include -o student_mgr` |

生成的可执行文件：`student_mgr`（或 Windows 下的 `student_mgr.exe`）

## 3. 运行

```bash
./student_mgr
```