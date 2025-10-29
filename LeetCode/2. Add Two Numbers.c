#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *results = NULL, *current = NULL;
    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry != 0){
        int sum = carry;

        if (l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }

        int value = sum % 10;

        carry = sum / 10;

        struct ListNode* newNode = createNode(value);
        if(results == NULL){
            results = newNode;
            current = newNode;
        }
        else {
            current->next = newNode;
            current = current->next;
        }
    }

    return results;
}

int main(void){

}