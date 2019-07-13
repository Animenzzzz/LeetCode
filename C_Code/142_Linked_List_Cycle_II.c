/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head) return NULL;
    //思路：用两个指针，一个slow指针，一个两倍速的fast指针遍历，fast返回空就不是循环，fast返回slow就是循环
    struct ListNode *slow = NULL;
    struct ListNode *fast = NULL;
    struct ListNode *head_tmp = head;

    if (!head->next || !head->next->next) {
        return NULL;
    }else{
        fast = head;
    }

    if (head->next->next == head) {
        return head;
    }
    

    slow = head->next;
    fast = head->next->next;
    head = head->next;
    while(head){
        slow = head;

        
        if (!head) {
            return NULL;
        }

        if (!fast->next || !fast->next->next) {
            return NULL;
        }else{

            //当有环时，慢指针设置为head，快指针步长设置为1，继续遍历，相遇的点就是入口。
            if (slow == fast) {
                slow = head_tmp;
                while(1){
                    if (slow->next == fast->next) {
                        return slow->next;
                    }
                    slow = slow->next;
                    fast = fast->next;
                    
                }
            }
            head = head->next;
            fast = fast->next->next;
        }
        
    }

    return NULL;
}