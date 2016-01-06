/**
 * @file linkedlist.h
 * @brief Declarations for LinkedList class
 * @author
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_LINKEDLIST_H_INCLUDE
#define GUARD_LINKEDLIST_H_INCLUDE

#include <linkedlist/linkedlist-config.h>

//! A double-linked list
class LINKEDLIST_EXPORT LinkedList {
    //
    //
    //
    //
    /*  DEFINITIONS    ----------------------------------------------------- */

public:

    /*  DEFINITIONS    ===================================================== */
    //
    //
    //
    //
    /*  DATA    ------------------------------------------------------------ */

private:

    LinkedList * previous_; /**< previous item */
    LinkedList * next_; /**< next item */

    /*  DATA    ============================================================ */
    //
    //
    //
    //
    /*  FUNCTIONS    ------------------------------------------------------- */


public:

    //! constructor
    explicit LinkedList ();

    //! destructor
    virtual
    ~LinkedList ();

    //! assignment operator
    LinkedList& operator=( const LinkedList& other) {
        previous_ = other.previous_;
        next_ = other.next_;
        return *this;
    }

    //! Finds out the number of elements that follow this one in the list.
    int
    lNextCount ();

    //! Extracts this instance from the list and ties the list.
    LinkedList *
    lExtract(
            LinkedList * first_item);

    //! Get previous item.
    LinkedList *
    lPrevious() {
        return previous_;
    }

    //! Get next item.
    LinkedList *
    lNext() {
        return next_;
    }

public:

    //! Inserts the item in the list as the first item.
    static LinkedList *
    lPushFront (
            LinkedList * first_item,
            LinkedList * new_item);

    //! Inserts the item in the list as the first item.
    static LinkedList *
    lPushBack (
            LinkedList * first_item,
            LinkedList * new_item);

    //! Inserts the item in the list as the first item.
    static inline LinkedList *
    preppend  (
            LinkedList * first_item,
            LinkedList * new_item) {
        return lPushFront (first_item, new_item);
    }

    //! Inserts the item in the list as the first item.
    static inline LinkedList *
    append (
            LinkedList * first_item,
            LinkedList * new_item) {
        return lPushBack (first_item, new_item);
    }

    //! Removes the first item.
    static LinkedList *
    lPopFront (
            LinkedList * first_item);

    //! Removes the last item.
    static LinkedList *
    lPopBack (
            LinkedList * first_item);

    //! Finds out the number of elements in the list.
    static int
    lCount (
            LinkedList * first_item) {
        if (first_item == NULL) return 0;
        else return first_item->lNextCount();
    }

    //! Deletes all elements in the list.
    static LinkedList *
    lClear (
            LinkedList * first_item);

    //! Get the item at a particular index.
    static LinkedList *
    lItem (
            LinkedList * first_item,
            int index);

    //! Get the first item.
    static LinkedList *
    lFirst (
            LinkedList * first_item) {
        return first_item;
    }

    //! Get the last item.
    static LinkedList *
    lLast (
            LinkedList * first_item);

public: virtual void anchorVtable() const;
}; // class LinkedList

#endif // GUARD_LINKEDLIST_H_INCLUDE
