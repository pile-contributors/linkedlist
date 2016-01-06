/**
 * @file linkedlist.cc
 * @brief Definitions for LinkedList class.
 * @author
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "linkedlist.h"
#include "linkedlist-private.h"

/**
 * @class LinkedList
 *
 * Detailed description.
 */

#if DEBUG_OFF
#define LKL_DEBUG DBG_PMESSAGE
#else
#define LKL_DEBUG black_hole
#endif

#if DEBUG_OFF
#define LKL_TRACE_ENTRY DBG_TRACE_ENTRY
#else
#define LKL_TRACE_ENTRY
#endif

#if DEBUG_OFF
#define LKL_TRACE_EXIT DBG_TRACE_EXIT
#else
#define LKL_TRACE_EXIT
#endif


/* ------------------------------------------------------------------------- */
LinkedList::LinkedList () :
    previous_ (NULL),
    next_ (NULL)
{
    LKL_TRACE_ENTRY;

    LKL_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
LinkedList::~LinkedList ()
{
    LKL_TRACE_ENTRY;

    LKL_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int LinkedList::lNextCount ()
{
    LKL_TRACE_ENTRY;

    int result = 0;
    LinkedList * iter = this;
    LinkedList * iter_next;
    for (;;) {
        iter_next = iter->next_;
        ++result;
        if (iter_next == NULL) break;
        iter = iter_next;
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
LinkedList * LinkedList::lExtract (LinkedList *first_item)
{
    LKL_TRACE_ENTRY;

    LinkedList * result = NULL;
    LinkedList * next = next_;
    LinkedList * previous = previous_;
    next_ = NULL;
    previous_ = NULL;
    for (;;) {
        if (previous == NULL) {
            // this is the first item

            if (next == NULL) {
                // this is the only item; the list becomes empty
                result = NULL;
                break;
            }

            // next item becomes the head of the list
            next->previous_ = NULL;
            result = next;

        } else {
            // not the first

            previous->next_ = next;
            if (next->previous_ != NULL) {
                // not last in list
                next->previous_ = previous;
            }

            // the head of the list does not change
            result = first_item;
        }

        break;
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
LinkedList *LinkedList::lPushFront (
        LinkedList *first_item, LinkedList *new_item)
{
    LKL_TRACE_ENTRY;

    LinkedList * result;
    if (new_item == NULL) {
        LKL_DEBUG ("  attempt to insert NULL item\n");
        result = first_item;
    } else {
        result = new_item;

        new_item->previous_ = NULL;
        new_item->next_ = first_item;

        if (first_item != NULL) {
            first_item->previous_ = new_item;
        }
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
LinkedList *LinkedList::lPushBack (
        LinkedList *first_item, LinkedList *new_item)
{
    LKL_TRACE_ENTRY;

    LinkedList * result;
    if (new_item == NULL) {
        LKL_DEBUG ("  attempt to insert NULL item\n");
        result = first_item;
    } else if (first_item == NULL) {
        // this is the only item in the list
        new_item->previous_ = NULL;
        new_item->next_ = NULL;
        result = new_item;
    } else {
        // head item does not change
        result = first_item;

        LinkedList * iter = first_item;
        LinkedList * iter_next;
        for (;;) {
            iter_next = iter->next_;
            if (iter_next == NULL) break;
            iter = iter_next;
        }

        new_item->previous_ = iter;
        new_item->next_ = NULL;

        iter->next_ = new_item;
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @warning The item is NOT deleted, it is simply extracted from the list.
 *
 * @param first_item Pointer to header item for the list.
 * @return new header item for the list
 */
LinkedList *LinkedList::lPopFront (LinkedList *first_item)
{
    LKL_TRACE_ENTRY;

    LinkedList * result;
    if (first_item == NULL) {
        LKL_DEBUG ("  attempt to remove first item from empty list\n");
        result = NULL;
    } else {
        result = first_item->next_;

        first_item->previous_ = NULL;
        first_item->next_ = NULL;

        if (result != NULL) {
            result->previous_ = NULL;
        }
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @warning The item is NOT deleted, it is simply extracted from the list.
 *
 * @param first_item Pointer to header item for the list.
 * @return new header item for the list
 */
LinkedList *LinkedList::lPopBack (LinkedList *first_item)
{
    LKL_TRACE_ENTRY;

    LinkedList * result;
    if (first_item == NULL) {
        LKL_DEBUG ("  attempt to remove last item from empty list\n");
        result = NULL;
    } else {
        // find last item
        LinkedList * iter = first_item;
        LinkedList * iter_next;
        for (;;) {
            iter_next = iter->next_;
            if (iter_next == NULL) break;
            iter = iter_next;
        }

        if (iter->previous_ == NULL) {
            // this is the only item in the list
            result = NULL;
        } else {
            // some other item
            iter->previous_->next_ = NULL;
            result = first_item;
        }

        iter->previous_ = NULL;
        iter->next_ = NULL;
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @param first_item Pointer to header item for the list.
 * @return new header item for the list - always NULL
 */
LinkedList *LinkedList::lClear (LinkedList *first_item)
{
    LKL_TRACE_ENTRY;

    if (first_item != NULL) {
        LinkedList * iter = first_item;
        LinkedList * iter_next;
        for (;;) {
            iter_next = iter->next_;

            delete iter;

            if (iter_next == NULL) break;
            iter = iter_next;
        }
    }

    LKL_TRACE_EXIT;
    return NULL;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @param first_item Pointer to header item for the list.
 * @param index the item to retrieve
 * @return the requested item or NULL if out of bounds
 */
LinkedList *LinkedList::lItem (LinkedList *first_item, int index)
{
    LKL_TRACE_ENTRY;
    LinkedList * result = NULL;

    if (first_item == NULL) {
        LKL_DEBUG ("  attempt to get item %d in an empty list\n", index);
    } else {
        LinkedList * iter = first_item;
        LinkedList * iter_next;
        int crt_index = 0;
        for (;;) {
            if (crt_index == index) {
                result = iter;
                break;
            }

            iter_next = iter->next_;
            if (iter_next == NULL) break;

            crt_index++;
            iter = iter_next;
        }
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @param first_item Pointer to header item for the list.
 * @return the requested item or NULL if the list is empty
 */
LinkedList *LinkedList::lLast (LinkedList *first_item)
{
    LKL_TRACE_ENTRY;
    LinkedList * result = first_item;

    if (first_item == NULL) {
        LKL_DEBUG ("  attempt to get last item in an empty list\n");
    } else {
        LinkedList * iter_next;
        for (;;) {
            iter_next = result->next_;
            if (iter_next == NULL) break;
            result = iter_next;
        }
    }

    LKL_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

void LinkedList::anchorVtable () const {}
