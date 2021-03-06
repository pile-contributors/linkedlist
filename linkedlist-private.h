/**
 * @file linkedlist-private.h
 * @brief Declarations for LinkedList class
 * @author 
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_LINKEDLIST_PRIVATE_H_INCLUDE
#define GUARD_LINKEDLIST_PRIVATE_H_INCLUDE

#include <linkedlist/linkedlist-config.h>

#if 0
#    define LINKEDLIST_DEBUGM printf
#else
#    define LINKEDLIST_DEBUGM black_hole
#endif

#if 0
#    define LINKEDLIST_TRACE_ENTRY printf("LINKEDLIST ENTRY %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define LINKEDLIST_TRACE_ENTRY
#endif

#if 0
#    define LINKEDLIST_TRACE_EXIT printf("LINKEDLIST EXIT %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define LINKEDLIST_TRACE_EXIT
#endif


static inline void black_hole (...)
{}

#endif // GUARD_LINKEDLIST_PRIVATE_H_INCLUDE
