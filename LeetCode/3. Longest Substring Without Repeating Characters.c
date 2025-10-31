#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int i = 0, j = 0, solution = 0, appeared[128];

    for(i = 0; i < 128; i++) appeared[i] = 0;
    
    for(i = 0; i < strlen(s); i++){

        int current_solution = 0;

        for(j = i; j < strlen(s); j++){
            
            if(!appeared[(int)s[j]]){
                current_solution++;
                appeared[(int)s[j]] = 1;
            } else {
                break;
            }
        }

        if(current_solution > solution) solution = current_solution;

        for(j = 0; j < 128; j++) appeared[j] = 0;
    }

    return solution;
}

int main(void){
    char s[] = " ";
    printf("%i", lengthOfLongestSubstring(s));
}