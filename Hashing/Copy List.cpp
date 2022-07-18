/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A == NULL) return A;
    
    RandomListNode* curr = A;
    while(curr){
        RandomListNode* node = new RandomListNode(curr->label);
        node->next = curr->next;
        curr->next = node;

        curr = curr->next->next;
    }

    curr = A;
    while(curr){
        curr->next->random = (curr->random ? curr->random->next : NULL);
        curr = curr->next->next;
    }

    RandomListNode *head = A->next, *randomlast = head;
    curr = A;
    while(curr){
        curr->next = curr->next->next;
        randomlast->next = (randomlast->next ? randomlast->next->next : NULL);

        curr = curr->next;
        randomlast = randomlast->next;
    }

    return head;
}
