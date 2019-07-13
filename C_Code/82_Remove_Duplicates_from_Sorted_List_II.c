/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    struct ListNode* head_tmp = head;
    struct ListNode* result = NULL;
    struct ListNode* result_head = NULL;

    if(!head) return NULL;

    if (head->next == NULL) {
        return head;
    }
    

    while(head){

        //头结点开始重复，要剔除头结点
        if (head->val == head->next->val) {
            while(head->val == head->next->val){

                head = head->next;
                if (!head) {
                    return result_head;
                }

                if (!head->next) {
                    break;
                }

                //3,3,4,4这种情况
                if (head->val != head->next->val) {
                    if (head->next->next) {
                        if (head->next->val == head->next->next->val) {
                            head = head->next;
                        }
                        
                    }
                    
                }
                
                
                
            }
            head = head->next;
            
            if (!result) {

                if (!head) {
                    return NULL;
                }
                

                struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = head->val;
                result = tmp;
                result_head = tmp;
            }else{

                if (head) {
                    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->next = NULL;
                    tmp->val = head->val;
                    result->next = tmp;
                    result = result->next;
                }
                
            }

            if (head){
                head = head->next;
            }
            
        //头结点不重复
        }else{
            if (!result) {

                if (!head) {
                    return NULL;
                }

                struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = head->val;
                result = tmp;
                result_head = tmp;
            }else{

                if (head) {
                    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->next = NULL;
                    tmp->val = head->val;
                    result->next = tmp;
                    result = result->next;
                }
                

            }

            if (head){
                head = head->next == NULL? NULL:head->next;
            }

            
        }

        if (!head) {
            break;
        }

        if (head->next == NULL) {
            result->next = head;
            break;
        }
        
        
    }
    
    printf("");
    return result_head;
    
}