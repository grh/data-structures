#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

/**
 * List: a doubly-linked list data structure
 */
template <class T>
class List {
    public:
        /* **************************************************************
         * ---------------------- CONSTRUCTORS ------------------------ *
         * **************************************************************/

        /**
         * <b>constructor</b>: create an empty List object\n
         * <b>parameters</b>: none\n
         * <b>return value</b>: n/a
         */
        List() {
            head = tail = nullptr;
            size = 0;
        }

        /**
         * <b>constructor</b>: create a List object containing a single item\n
         * <b>parameters</b>: an item\n
         * <b>return value</b>: n/a
         */
        List(const T &item) : List<T>() {
            insert(item);
        }

        /**
         * <b>constructor</b>: deep copy a List object into a new List object\n
         * <b>parameters</b>: a List object\n
         * <b>return value</b>: n/a
         */
        List(const List<T> &list) {

        }

        /* **************************************************************
         * ---------------- PUBLIC MEMBER FUNCTIONS ------------------- *
         * **************************************************************/

        /**
         * <b>append</b>: add an item at the end of the list\n
         * <b>parameters</b>: an item\n
         * <b>return value</b>: none
         */
        void append(const T &item) {
            ListNode<T> *newNode = new ListNode<T>(item);

            if (isEmpty()) {
                head = tail = newNode;
            } else {
                tail->setNext(newNode);
                newNode->setPrev(tail);
                tail = newNode;
            }

            //_sort();
        }

        /**
         * <b>contains</b>: check if the list contains an item\n
         * <b>parameters</b>: an item\n
         * <b>return value</b>: true if the item is in the list, false otherwise
         */
        bool contains(const T &item) const {

        }

        /**
         * <b>find</b>: find and return the position of an item\n
         * <b>parameters</b>: an item\n
         * <b>return value</b>: the position of the item if found, -1 otherwise
         */
        int find(const T &item) const {

        }

        /**
         * <b>insert</b>: insert an item into the linked list\n
         * <b>parameters</b>: an item\n
         * <b>return value</b>: none
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

            size++;
        }

        /**
         * <b>isEmpty</b>: test if the list is empty or not\n
         * <b>parameters</b>: none\n
         * <b>return value</b>: true if the list has no nodes in it, 
         *                   false otherwise
         */
        bool isEmpty() {
            return head == nullptr and tail == nullptr;
        }

        /**
         * <b>operator=</b>: deep copy another List object\n
         * <b>parameters</b>: a List object\n
         * <b>return value</b>: none
         */
        void operator=(const List<T> &rhs) {

        }

        /**
         * <b>operator[]</b>: access an item by position\n
         * <b>parameters</b>: a position\n
         * <b>return value</b>: the item at that position
         */
        T & operator[](const int &pos) const {
            if (pos >= size) {
                throw;
            }

            int i = 0;
            ListNode<T> *ptr = head;

            while (i <= pos and ptr != nullptr) {
                i++;
                ptr = ptr->getNext();
            }

            return ptr->getItem();
        }

        /**
         * <b>prepend</b>: add an item at the beginning of the list\n
         * <b>parameters</b>: an item\n
         * <b>return value</b>: none
         */
        void prepend(const T &item) {
            ListNode<T> *newNode = new ListNode<T>(item);

            if (isEmpty()) {
                head = tail = newNode;
            } else {
                head->setPrev(newNode);
                newNode->setNext(tail);
                head = newNode;
            }

            //_sort();
        }

        /**
         * <b>remove</b>: remove an item at a given position\n
         * <b>parameters</b>: a position\n
         * <b>return value</b>: none
         */
        void remove(const int &pos) {

        }

        /**
         * <b>slice</b>: remove all the items in a given range\n
         * <b>parameters</b>: a start and end position\n
         * <b>return value</b>: none
         */
        void slice(const int &start, const int &end) {

        }

    private:
        ListNode<T> *head, *tail;
        int size;
};

#endif
