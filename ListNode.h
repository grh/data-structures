#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "Node.h"

/**
 * ListNode: a class representing a linked list node
 * public methods:
 *     constructors: empty, single item, ListNode object
 *     navigation: getNext, getPrev
 *     modification: setNext, setPrev
 */
template <class T>
class ListNode : public Node<T> {
    public:
        /**
         * constructor: create an empty ListNode object
         * parameters: none
         * return value: n/a
         */
        ListNode() {
            nextPtr = prevPtr = nullptr;
        }

        /**
         * constructor: create a ListNode object from an item
         * parameters: an item
         * return value: n/a
         */
        ListNode(const T &i) : ListNode<T>() {
            this->_initialize(i);
        }

        /**
         * constructor: create a ListNode object from another ListNode
         * parameters: a ListNode object
         * return value: n/a
         */
        ListNode(ListNode &node) {
            this->_initialize(node);
            nextPtr = node.getNext();
            prevPtr = node.getPrev();
        }

        /**
         * getNext: retrieve the pointer to the next node
         * parameters: none
         * return value: the pointer to the next node
         */
        ListNode * getNext() {
            return nextPtr;
        }

        /**
         * getPrev: retrieve the pointer to the previous node
         * parameters: none
         * return value: the pointer to the previous node
         */
        ListNode * getPrev() {
            return prevPtr;
        }

        /**
         * setNext: update the pointer to the next node
         * parameters: a pointer to a ListNode object
         * return value: none
         */
        void setNext(ListNode<T> *ptr) {
            nextPtr = ptr;
        }

        /**
         * setPrev: update the pointer to the previous node
         * parameters: a pointer to a ListNode object
         * return value: none
         */
        void setPrev(ListNode<T> *ptr) {
            prevPtr = ptr;
        }

    private:
        ListNode<T> *nextPtr, *prevPtr;
};

#endif
