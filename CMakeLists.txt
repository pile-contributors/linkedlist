if (NOT LINKEDLIST_BUILD_MODE)
    set (LINKEDLIST_BUILD_MODE STATIC)
endif ()

include(pile_support)
pileInclude (LinkedList)
linkedlistInit(${LINKEDLIST_BUILD_MODE})
