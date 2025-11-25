#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student *student_new(int id, const char *name, float score)
{
    Student *s = malloc(sizeof *s);
    s->id    = id;
    strncpy(s->name, name, sizeof s->name - 1);
    s->name[sizeof s->name - 1] = '\0';
    s->score = score;
    s->next  = NULL;
    return s;
}

void student_swap(Student *a, Student *b)
{
    Student tmp = *a;
    *a = *b;
    *b = tmp;
    /* 恢复链表指针 */
    tmp.next = a->next;
    a->next  = b->next;
    b->next  = tmp.next;
}

void student_print(const Student *s)
{
    printf("%d\t%-10s %.1f\n", s->id, s->name, s->score);
}

int student_compare_by_score(const Student *a, const Student *b)
{
    return a->score < b->score;   // 降序
}