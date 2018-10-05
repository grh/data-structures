#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

/**
 * List: a doubly-linked list data structure
 * public methods:
 *     constructors: empty, single item, another List object
 *     insertion: insert, append, prepend
 *     access: [], contains, find
 *     remove: remove, slice
 *     list state: isEmpty
 */
template <class T>
class List {
    public:
        /**
         * constructor: create an empty List object
         * parameters: none
         * return value: n/a
         */
        List() {
            head = tail = nullptr;
        }

        /**
         * constructor: create a List object containing a single item
         * parameters: an item
         * return value: n/a
         */
        List(const T &item) : List<T>() {
            insert(item);
        }

        /**
         * constructor: deep copy a List object into a new List object
         * parameters: a List object
         * return value: n/a
         */
        List(const List<T> &list) {

        }

        /**
         * insert: insert an item into the linked list
         * parameters: an item
         * return value: none
         */
        void insert(const T &item) {
            // create a new node with the item
            // if the list is empty
            //     update head and tail pointers to point to the new node
            // otherwise
            //     start at the head
            //     while the next item is less than the new item
            //         go to the next node
            //     update the new node to point to the next and previous nodes
            //     update the previous and next pointers to point to the new node
            ListNode<T> *newNode = new ListNode<T>(item);

            if (isEmpty()) {
                head = tail = newNode;
            } else {
                ListNode<T> *ptr = head;

                // pre-condition: ptr points to head
                while (ptr != tail and ptr->getItem() <= item) {
                    ptr = ptr->getNext();
                }

                // post-condition: ptr points to tail
                //                 or ptr->getItem() is greater than item
                if (ptr == tail) {
                    newNode->setPrev(ptr);
                    ptr->setNext(newNode);
                    tail = newNode;
                } else {
                    newNode->setPrev(ptr->getPrev());
                    newNode->setNext(ptr);
                    ptr->getPrev()->setNext(newNode);
                    ptr->setPrev(newNode);
                }
            }
        }

        /**
         * isEmpty: test if the list is empty or not
         * parameters: none
         * return value: true: if the list has no nodes in it
         *               false: otherwise
         */
        bool isEmpty() {
            return head == nullptr and tail == nullptr;
        }
    private:
        ListNode<T> *head, *tail;
};

#endif
