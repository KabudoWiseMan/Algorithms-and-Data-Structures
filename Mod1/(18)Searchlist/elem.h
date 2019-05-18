#ifndef ELEM_H_INCLUDED
#define ELEM_H_INCLUDED

struct Elem {
    enum {
        INTEGER,
        FLOAT,
        LIST
    } tag;
    
    union {
        int i;
        float f;
        struct Elem *list;
    } value;
    
    struct Elem *tail;
};

#endif
