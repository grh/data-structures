#ifndef NODE_H
#define NODE_H

/**
 * Node: a base class for node objects used in various data structures
 * public methods:
 *     constructors: single item, another Node object
 *     modification: getItem, setItem
 */
template <class T>
class Node {
    public:
        /**
         * getItem: retrieve the item stored in the Node object
         * parameters: none
         * return value: the item
         */
        T & getItem() {
            return _item;
        }

        /**
         * setItem: update the item stored in the Node object
         * parameters: an item
         * return value: none
         */
        void setItem(T &i) {
            _item = i;
        }

    protected:
        T _item;

        /**
         * _initialize: initialize a Node object given a single item
         * parameters: an item
         * return value: none
         */
        void _initialize(const T &i) {
            _item = i;
        }

        /**
         * _initialize: initialize a Node object from another Node object
         * parameters: a Node object
         * return value: none
         */
        void _initialize(Node<T> &node) {
            _item = node.getItem();
        }
};

#endif
