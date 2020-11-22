#include <stdio.h>
#include <stdlib.h>


struct Tries {
    int End;
    struct Tries *Children[26]; // 'a' - 'z'
};

// TODO