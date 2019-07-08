/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 思路：1.先反转链表 2.链表相加

    struct ListNode *l1_revo_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1_revo_head->val = 0;
    l1_revo_head->next = NULL;


    struct ListNode *l2_revo_head = (struct ListNode *)malloc(sizeof(struct  ListNode));
    l2_revo_head->val = 0;
    l2_revo_head->next = NULL;

    

    while(l1 || l2){

        if (l1) {


            if (l1_revo_head->next == NULL) {
                struct ListNode *l1_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                l1_tmp->val = l1->val;
                l1_tmp->next  =NULL;
                l1_revo_head->next = l1_tmp;
            }else{
                struct ListNode *l1_revo_next_tmp = l1_revo_head->next;

                struct ListNode *l1_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                l1_tmp->val = l1->val;
                l1_tmp->next  =NULL;

                l1_tmp->next = l1_revo_next_tmp;

                l1_revo_head->next = l1_tmp;
            }
            l1 = l1->next == NULL ? NULL:l1->next;
        }


        if (l2) {


            if (l2_revo_head->next == NULL) {
                struct ListNode *l2_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                l2_tmp->val = l2->val;
                l2_tmp->next  =NULL;
                l2_revo_head->next = l2_tmp;
            }else{
                struct ListNode *l2_revo_next_tmp = l2_revo_head->next;

                struct ListNode *l2_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                l2_tmp->val = l2->val;
                l2_tmp->next  =NULL;

                l2_tmp->next = l2_revo_next_tmp;

                l2_revo_head->next = l2_tmp;
            }
            l2 = l2->next == NULL ? NULL:l2->next;
        }

        
    }

    printf("");

    struct ListNode *l1_reverse = l1_revo_head->next;
    struct ListNode *l2_reverse = l2_revo_head->next;

    struct ListNode *result = NULL;
    struct ListNode *result_head = NULL;
    int jinwei = 0;
    int flag = 0;
    while(l1_reverse || l2_reverse){

        

        int l1_val = l1_reverse == NULL ? 0:l1_reverse->val;
        int l2_val = l2_reverse == NULL ? 0:l2_reverse->val;

        int sum = l1_val+l2_val+jinwei;
        if(sum >=10){
            jinwei = 1;
            struct ListNode *result_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            result_tmp->val = sum%10;
            result_tmp->next = NULL;
            //第一次进入循环，为了存储头指针
            if(result == NULL){
                flag = 1;
                result = result_tmp;
                result_head = result_tmp;
            }else{
                result->next = result_tmp;
            }
            
            
        }else{
            jinwei = 0;
            struct ListNode *result_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            result_tmp->val = sum%10;
            result_tmp->next = NULL;
            //第一次进入循环，为了存储头指针
            if(result == NULL){
                flag = 1;
                result = result_tmp;
                result_head = result_tmp;
            }else{
                result->next = result_tmp;
            }
        }

        

        l1_reverse = l1_reverse == NULL ? NULL:l1_reverse->next;
        l2_reverse = l2_reverse == NULL ? NULL:l2_reverse->next;
        result = result->next == NULL ? result:result->next;

        if(!l1_reverse && !l2_reverse){
            if(jinwei){
                struct ListNode *result_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                result_tmp->val = 1;
                result_tmp->next = NULL;
                result->next = result_tmp;
            }
        }
    }

    //得到的结果再反转一次
    struct ListNode *result_result = NULL;
   
    while(result_head){

        if (result_head) {


            if (result_result == NULL) {
                struct ListNode *l1_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                l1_tmp->val = result_head->val;
                l1_tmp->next  =NULL;
                result_result = l1_tmp;
                
                
            }else{
                struct ListNode *l1_revo_next_tmp = result_result;

                struct ListNode *l1_tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
                l1_tmp->val = result_head->val;
                l1_tmp->next  =NULL;

                l1_tmp->next = l1_revo_next_tmp;

                result_result = l1_tmp;
            }
            result_head = result_head->next == NULL ? NULL:result_head->next;
        }
    }
    printf("");
    return result_result;
}