#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

/* 适配器：让通用链表能识别 Student 的 id */
static int match_by_id(const void *data, int key)
{
    return ((const Student *)data)->id == key;
}

/* 释放单个学生 */
static void free_student(void *s) { free(s); }

static Node *g_head = NULL;   // ui 模块私有的“句柄”

static void insert_ui(void)
{
    int id; char name[20]; float score;
    printf("学号 姓名 成绩：");
    scanf("%d%s%f", &id, name, &score);
    list_push_front(&g_head, student_new(id, name, score));
}

static void delete_ui(void)
{
    int id;
    printf("待删学号：");
    scanf("%d", &id);
    printf(list_remove(&g_head, match_by_id, id) ? "已删除\n" : "未找到\n");
}

static void find_ui(void)
{
    int id;
    printf("待查学号：");
    scanf("%d", &id);
    Student *s = list_find(g_head, match_by_id, id);
    s ? student_print(s) : puts("未找到");
}

static void sort_ui(void)
{
    list_sort(g_head,
              (int (*)(const void *, const void *))student_compare_by_score,
              (void (*)(void *, void *))student_swap);
    puts("已按成绩降序排序");
}

static void print_ui(void)
{
    puts("\n=== 学生列表 ===");
    for (Node *p = g_head; p; p = p->next)
        student_print(p->data);
}

void ui_run(void)
{
    for (;;) {
        puts("\n1.插入 2.删除 3.查找 4.排序 5.打印 0.退出");
        printf("请选择：");
        int c;  if (scanf("%d", &c) != 1) break;
        switch (c) {
        case 1: insert_ui(); break;
        case 2: delete_ui(); break;
        case 3: find_ui();   break;
        case 4: sort_ui();   break;
        case 5: print_ui();  break;
        case 0: goto end;
        default: puts("输入错误");
        }
    }
end:
    list_free(&g_head, free_student);
}