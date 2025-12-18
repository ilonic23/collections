#include "collections.h"
#include "stdio.h"
#include "assert.h"

void main() {
    linked_list_t *list;
    int vals[5] = {0, 1, 2, 3, 4};
    linked_list_node_t *node1, *node2, *node3, *node4, *node5;

    printf("---- Collections Tests ----\n");
    printf("\n Singly Linked List\n");
    printf("1. linked_list_init ");
    list = linked_list_init();
    assert(list);
    printf("SUCCESS\n");
    printf("2. linked_list_node_init ");
    node1 = linked_list_node_init(&vals[0]);
    node2 = linked_list_node_init(&vals[1]);
    node3 = linked_list_node_init(&vals[2]);
    node4 = linked_list_node_init(&vals[3]);
    node5 = linked_list_node_init(&vals[4]);
    assert(node1 && node2 && node3 && node4 && node5);
    printf("SUCCESS\n");
    printf("3. linked_list_append ");
    linked_list_append(list, node1);
    assert(node1 == list->head && node1 == list->tail && list->length == 1);
    printf("SUCCESS\n");
    printf("4. linked_list_append 2 ");
    linked_list_append(list, node2);
    assert(node1 == list->head && node2 == list->tail && list->length == 2);
    printf("SUCCESS\n");
    printf("5. linked_list_append 3 ");
    linked_list_append(list, node3);
    assert(node1 == list->head && node3 == list->tail && list->length == 3 && list->head->next == node2);
    printf("SUCCESS\n");
    printf("6. linked_list_node_at ");
    assert(list->head == linked_list_node_at(list, 0));
    printf("SUCCESS\n");
    printf("7. linked_list_node_at 1 ");
    assert(node2 == linked_list_node_at(list, 1));
    printf("SUCCESS\n");
    printf("8. linked_list_node_at 2 ");
    assert(list->tail == linked_list_node_at(list, 2));
    printf("SUCCESS\n");
    printf("9. linked_list_at ");
    assert(0 == *(int *)linked_list_at(list, 0));
    printf("SUCCESS\n");
    printf("10. linked_list_at 1 ");
    assert(1 == *(int *)linked_list_at(list, 1));
    printf("SUCCESS\n");
    printf("11. linked_list_at 2 ");
    assert(2 == *(int *)linked_list_at(list, 2));
    printf("SUCCESS\n");
    printf("12. linked_list_remove ");
    linked_list_remove(list, 2);
    assert(list->tail == node2);
    printf("SUCCESS\n");
    printf("13. linked_list_insert_at ");
    linked_list_insert_at(list, 1, node4);
    assert(list->head->next == node4);
    printf("SUCCESS\n");
    printf("14. linked_list_set_at ");
    linked_list_set_at(list, 1, node5->value);
    assert(list->head->next->value == node5->value);
    printf("SUCCESS\n");
    printf("15. linked_list_clear ");
    linked_list_clear(list);
    int iter = 0;
    for (; iter < list->length; iter++) ;
    assert(0 == iter);
    printf("SUCCESS\n");

    linked_list_free(list);
}