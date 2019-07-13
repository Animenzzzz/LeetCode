/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
        
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = NULL;

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head= result;
    // head->next = NULL;

    int jinwei = 0;

    //2,4,3
    //5,6,4
    while(l1 || l2){


        int l1_val = 0;
        int l2_val = 0;

        if (l1 != NULL) {
            l1_val = l1->val;
        }

        if (l2 != NULL) {
            l2_val = l2->val;
        }
        

        int sum = l1_val + l2_val + jinwei;
        if (sum >=10) {
            jinwei = 1;
        }else{
            jinwei = 0;
        }
        
        
        l1 = l1 == NULL ? NULL:l1->next;
        l2 = l2 == NULL ? NULL:l2->next;

        if (!l1 && !l2) {
            result->val = sum%10;
            if (sum>=10) {
                result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                result->next->next = NULL;
                result->next->val = (sum-sum%10)%10+1;
            }
            
            break;
        }else{
            result->val = sum%10;
            result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            result->next->next = NULL;
            result = result->next;
        }
        
    
    }
    return head;
}