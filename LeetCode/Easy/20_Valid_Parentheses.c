#include <stdio.h>
#include <stdbool.h>

#define false 0
#define true 1

bool isValid(char * s){

    int len = strlen(s);

    char *string = (char *)malloc(800000 * sizeof(char));
    int pos = -1;

    if (len == 0) { return true; }
    if (len == 1) { return false; }
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            string[++pos] = s[i];
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (pos == -1) { return false; }
            if (s[i] == ')' && string[pos] == '(') { 
                pos--; 
            } else if (s[i] == ']' && string[pos] == '[') { 
                pos--; 
            } else if (s[i] == '}' && string[pos] == '{') { 
                pos--; 
            } else {
                return false;
                //string[++pos] = s[i];
            }
        }
    }
    
    if (pos == -1) {
        return true;
    } else {
        return false;
    }
}