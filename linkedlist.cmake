
# enable/disable cmake debug messages related to this pile
set (LINKEDLIST_DEBUG_MSG ON)

# make sure support code is present; no harm
# in including it twice; the user, however, should have used
# pileInclude() from pile_support.cmake module.
include(pile_support)

# initialize this module
macro    (linkedlistInit
          ref_cnt_use_mode)

    # default name
    if (NOT LINKEDLIST_INIT_NAME)
        set(LINKEDLIST_INIT_NAME "LinkedList")
    endif ()

    # compose the list of headers and sources
    set(LINKEDLIST_HEADERS
        "linkedlist.h")
    set(LINKEDLIST_SOURCES
        "linkedlist.cc")

    pileSetSources(
        "${LINKEDLIST_INIT_NAME}"
        "${LINKEDLIST_HEADERS}"
        "${LINKEDLIST_SOURCES}")

    pileSetCommon(
        "${LINKEDLIST_INIT_NAME}"
        "0;0;1;d"
        "ON"
        "${ref_cnt_use_mode}"
        ""
        "category1"
        "tag1;tag2")

endmacro ()
