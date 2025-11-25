#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int   id;
    char  name[20];
    float score;
    struct Student *next;
} Student;

/* 业务接口 */
Student *student_new(int id, const char *name, float score);
void     student_swap(Student *a, Student *b);
void     student_print(const Student *s);
int      student_compare_by_score(const Student *a, const Student *b);

#endif