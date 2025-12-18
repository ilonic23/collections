#include "collections.h"
#include "stdlib.h"

// Singly linked list implementation

linked_list_t* linked_list_init(void) {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if (!list) return NULL;
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
}

linked_list_node_t* linked_list_node_init(void* value) {
    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
    if (!node) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void linked_list_node_free(linked_list_node_t* node) {
    free(node);
}

void linked_list_append(linked_list_t* list, linked_list_node_t* node) {
    if (!list || !node) return;

    if (!list->head) // If the head is null
    {
        list->head = node;
        list->tail = node; // The tail shouldn't have the value at this point.
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    list->length++;
}

linked_list_node_t* linked_list_node_at(linked_list_t* list, size_t index) {
    if (!list) return NULL;
    if (index >= list->length && index != 0) return NULL; // Allow 0 to be index here
    linked_list_node_t *node = list->head;
    for (int i = 0; i < index; i++)
    {
        if (!node || !node->next) return NULL;
        node = node->next;
    }
    return node;
}

void* linked_list_at(linked_list_t* list, size_t index) {
    linked_list_node_t *node = linked_list_node_at(list, index);
    if (!node) return NULL;
    return node->value;
}

void linked_list_remove(linked_list_t* list, size_t index) {
    if (!list) return;
    if (index >= list->length) return;

    if (!index) // Remove first node
    {
        linked_list_node_t *to_free = list->head;
        if (!to_free) return;

        list->head = to_free->next;
        if (!list->head) {
            list->tail = NULL;
        }
        linked_list_node_free(to_free);
    }
    else
    {
        linked_list_node_t *left = linked_list_node_at(list, index - 1);
        linked_list_node_t *node = linked_list_node_at(list, index);

        if (!left || !node) return;

        left->next = node->next;
        if (!node->next) { // Removing last node
            list->tail = left;
        }
        linked_list_node_free(node);
    }

    list->length--;
}

void linked_list_insert_at(linked_list_t* list, size_t index, linked_list_node_t* node) {
    if (!list || !node) return;
    if (index > list->length) return; // Allow insertion at end

    if (!index) // Insert at beginning
    {
        node->next = list->head;
        list->head = node;
        if (!node->next) { // List was empty
            list->tail = node;
        }
    }
    else
    {
        linked_list_node_t *left = linked_list_node_at(list, index - 1);
        if (!left) return;

        node->next = left->next;
        left->next = node;

        if (!node->next) { // Inserted at end
            list->tail = node;
        }
    }
    list->length++;
}

void linked_list_set_at(linked_list_t* list, size_t index, void* value) {
    if (!list) return;
    if (index >= list->length && index != 0) return;
    linked_list_node_t *node = linked_list_node_at(list, index);
    if (!node) return;
    node->value = value;
}

void linked_list_clear(linked_list_t* list) {
    for (size_t i = 0; i < list->length; i++)
        linked_list_remove(list, i);
    list->length = 0;
}

void linked_list_free(linked_list_t* list) {
    linked_list_clear(list);
    free(list);
}

// Singly linked list implementation