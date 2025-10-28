#include <stdio.h>

int countValidSelections(int* nums, int numsSize){
    int i = 0, j = 0, solutions = 0;
    for(i = 0; i < numsSize; i++){
        int pivot = 0;
        if(nums[i] != 0) continue;
        else {
            pivot = i;
            int left = 0, right = 0;
            for(j = 0; j < pivot; j++){
                left+=nums[j];
            }
            for(j = pivot+1; j < numsSize; j++){
                right+=nums[j];
            }
            if(left == right) solutions += 2;
            if(left+1 == right || left == right+1) solutions+=1;
        }
    }

    return solutions;
}

int main(void){
    int array[] = {16,13,10,0,0,0,10,6,7,8,7};
    size_t number_of_elements = sizeof(array)/sizeof(array[0]);
    printf("%i", countValidSelections(array, number_of_elements));
    return 0;
}