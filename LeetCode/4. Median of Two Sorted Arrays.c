#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mergedArray[nums1Size+nums2Size], i = 0, /*nums1Visited[nums1Size], nums2Visited[nums2Size],*/ left = 0, right = 0;
    int newSize = nums1Size+nums2Size;

    while(left < nums1Size && right < nums2Size){
        if(nums1[left] < nums2[right]){
            mergedArray[i] = nums1[left];
            left++;
        }
        else {
            mergedArray[i] = nums2[right];
            right++;
        }
        i++;
    }

    while(left < nums1Size) {
        mergedArray[i] = nums1[left];
        left++;
        i++;
    }

    while(right < nums2Size) {
        mergedArray[i] = nums2[right];
        right++;
        i++;
    }

    // for(i = 0; i < nums1Size; i++) nums1Visited[i] = 0;
    // for(i = 0; i < nums2Size; i++) nums2Visited[i] = 0;

    // for(i = 0; i < newSize; i++){
        
    //     if(nums1[left] < nums2[right] && !nums1Visited[left]){
    //         mergedArray[i] = nums1[left];
    //         nums1Visited[left] = 1;
    //         left++;
    //         if(left > nums1Size) left = nums1Size - 1;
    //     } 
    //     else if(nums1[left] > nums2[right] && !nums2Visited[right]){
    //         mergedArray[i] = nums2[right];
    //         nums2Visited[right] = 1;
    //         right++;
    //         if(right > nums2Size) right = nums2Size - 1;
    //     }
    //     else if(nums1[left] == nums2[right]){
    //         if(!nums1Visited[left]){
    //             mergedArray[i] = nums1[left];
    //             nums1Visited[left] = 1;
    //             left++;
    //             if(left > nums1Size) left = nums1Size - 1;
    //         } else {
    //             mergedArray[i] = nums2[right];
    //             nums2Visited[right] = 1;
    //             right++;
    //             if(right > nums2Size) left = nums2Size - 1;
    //         }
    //     }
    // }

    if (newSize % 2 == 0) {
        double m1 = mergedArray[(newSize/2) - 1];
        double m2 = mergedArray[(newSize/2)];
        return (double)((m1 + m2)/2);
    }
    else return (double)(mergedArray[newSize/2]);
}

int main(void){
    int nums1[] = {}, nums2[] = {1};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);

    printf("%f", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}