/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(!head) return NULL;

    if (head->next == NULL) {
        return head;
    }

    struct ListNode* head_tmp = head;
    int position_value = x;
    
    printf("");
    head_tmp = head;
    struct ListNode* small = NULL;
    struct ListNode* big = NULL;

    struct ListNode* small_head = NULL;
    struct ListNode* big_head = NULL;

    while(head_tmp){

        if (head_tmp->val >= position_value) {//big

            if (!big_head) {// big  头
                struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = head_tmp->val;
                big = tmp;
                big_head = tmp;
            }else{
                struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = head_tmp->val;
                big->next = tmp;
                big = big->next;
            }
            
        }else{//small

            if (!small_head) {// small  头
                struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = head_tmp->val;
                small = tmp;
                small_head = tmp;
            }else{
                struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = head_tmp->val;
                small->next = tmp;
                small = small->next;
            }

        }
        
        head_tmp = head_tmp->next != NULL ? head_tmp->next : NULL;
    }

    if (!small_head) {
        return big_head;
    }
    
    small->next = big_head;
    printf("");
    return small_head;
}