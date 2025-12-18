#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#include <stddef.h>

// Singly linked list implementation

typedef struct LinkedListNode
{
    void *value;
    struct LinkedListNode *next;
} linked_list_node_t;

typedef struct
{
    size_t length;
    linked_list_node_t *head;
    linked_list_node_t *tail;
} linked_list_t;

/**
 * @brief Initializes the linked list.
 * @return Initialized linked list pointer. NULL if failed.
 */
linked_list_t *linked_list_init(void);

/**
 * @brief *Initializes a linked list node.
 * @return Initialized node pointer. NULL if failed.
 */
linked_list_node_t *linked_list_node_init(void *value);

/**
 * Frees the memory of the node.
 * @param node The node to free the memory of.
 */
void linked_list_node_free(linked_list_node_t *node);

/**
 * @brief Append a node to the tail.
 * @param list The list to append the node to.
 * @param node The node to append to.
 */
void linked_list_append(linked_list_t *list, linked_list_node_t *node);

/**
 * @brief Get a node from the list at a specific index.
 * @param list The list to get the node from.
 * @param index The index to get the node at.
 * @return Pointer to the node. NULL if it doesn't exist.
 */
linked_list_node_t *linked_list_node_at(linked_list_t *list, size_t index);

/**
 * @brief Get a value from the list at a specific index.
 * @param list The list to get the value from.
 * @param index The index to get the value at.
 * @return
 */
void *linked_list_at(linked_list_t *list, size_t index);

/**
 * @brief Remove a node from the list at a specific index.
 * Nodes that were disconnected will be reconnected.
 * The node's memory will be freed.
 * @param list The list to remove the node from.
 * @param index The index to remove the node at.
 * If the index points farther than the tail nothing would happen.
 */
void linked_list_remove(linked_list_t *list, size_t index);

/**
 * @brief Inserts a node to the list at the index.
 * @param list The list to insert the node to.
 * @param index The index to insert the node at.
 * If the index points farther than the tail the node wouldn't be inserted.
 * @param node The node to insert.
 */
void linked_list_insert_at(linked_list_t *list, size_t index, linked_list_node_t *node);

/**
 * @brief
 * @param list The list to change the value in.
 * @param index The index to set the value at.
 * If the index points farther than the tail nothing would happen.
 * @param value The value to set.
 */
void linked_list_set_at(linked_list_t *list, size_t index, void *value);

/**
 * Clears the list of every node and frees memory of all the nodes.
 * @param list The list to clear.
 */
void linked_list_clear(linked_list_t *list);

/**
 * Clears the list and then frees it's memory.
 * @param list The list to free the memory of.
 */
void linked_list_free(linked_list_t *list);

// Singly linked list implementation

#endif