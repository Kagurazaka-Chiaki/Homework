// hello world

#include <iostream>



#ifndef DEBUG
    #define DEBUG 1
#endif

#ifdef  DEBUG
    #define debug if (1)
#else
    #define debug if (0)
#endif

int main() {
    
    debug {
        std::cout << "Hello World!" << std::endl;
    }
    
    return 0;
}