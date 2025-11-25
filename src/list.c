#include <stdlib.h>
#include "list.h"

void list_push_front(Node **head, void *data)
{
    Node *n = malloc(sizeof *n);
    n->data = data;
    n->next = *head;
    *head   = n;
}

int list_remove(Node **head, int (*match)(const void *, int), int key)
{
    Node *p = *head, *prev = NULL;
    while (p) {
        if (match(p->data, key)) {
            if (prev) prev->next = p->next;
            else      *head = p->next;
            free(p);
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0;
}

void *list_find(Node *head, int (*match)(const void *, int), int key)
{
    while (head) {
        if (match(head->data, key)) return head->data;
        head = head->next;
    }
    return NULL;
}

/* 选择排序，仅交换 data 指针 */
void list_sort(Node *head,
               int (*less)(const void *, const void *),
               void (*swap)(void *, void *))
{
    for (Node *i = head; i; i = i->next) {
        Node *min = i;
        for (Node *j = i->next; j; j = j->next)
            if (less(j->data, min->data)) min = j;
        if (min != i) swap(&i->data, &min->data);
    }
}

void list_free(Node **head, void (*free_data)(void *))
{
    while (*head) {
        Node *tmp = *head;
        *head = tmp->next;
        if (free_data) free_data(tmp->data);
        free(tmp);
    }
}