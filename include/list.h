#ifndef LIST_H
#define LIST_H

typedef struct Node {
    void              *data;
    struct Node       *next;
} Node;

/* 通用链表接口 */
void      list_push_front(Node **head, void *data);
int       list_remove(Node **head, int (*match)(const void *, int), int key);
void     *list_find(Node *head, int (*match)(const void *, int), int key);
void      list_sort(Node *head,
                    int (*less)(const void *, const void *),
                    void (*swap)(void *, void *));
void      list_free(Node **head, void (*free_data)(void *));
#endif