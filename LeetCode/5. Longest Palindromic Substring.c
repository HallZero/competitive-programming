#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    size_t size = strlen(s);
    int i = 0, j = 0, start = 0, end = 0;

    for(i; i < size; i++){
        for(j = i; j < size; j++){

            if(s[j] == s[i]){
                int left = i, right = j;

                while(left <= right){
                    if(s[left] != s[right]){
                        break;
                    }
                    left++;
                    right--;
                }

                if((left == right && (j-i) > (end-start)) || (left > right && (j-i) > (end-start))){
                    start = i;
                    end = j;
                }
            }
        }
    }

    char* result = (char*)malloc(end-start+2);

    if(result == NULL) return NULL;

    memcpy(result, &s[start], end-start+1);
    
    result[end-start+1] = '\0';

    return result;
}

int main(void){
    char* s = "bacbaab";
    printf("%s", longestPalindrome(s));
}