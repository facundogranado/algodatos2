#include "strfuncs.h"
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str){
    size_t r = 0;
    if (str!=NULL){
       while (str[r]!='\0'){
              r++;
          }
       }
    return r;
}

char *string_filter(const char *str, char c){
    size_t l = string_length(str);
    char r[l];
    size_t j = 0;
    for (unsigned i = 0; i < l; i++){
        if (str[i]!=c){
            r[j]=str[i];
            j++;
        }
    }
    char *filtered = malloc(j+1);

    for(unsigned int i=0; i<=l; i++) {
        filtered[i] = r[i];
    }
    return filtered;
}