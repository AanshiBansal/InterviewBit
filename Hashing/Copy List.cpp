//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.
//Return a deep copy of the list.
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* help=new RandomListNode(0);
    RandomListNode* ans=help;
    unordered_map<RandomListNode*, RandomListNode*>mp;
    while(A){
        if(mp.find(A)==mp.end())
        mp[A]=new RandomListNode(A->label);
        if(A->next&&mp.find(A->next)==mp.end())
        mp[A->next]=new RandomListNode(A->next->label);
        if(A->random&&mp.find(A->random)==mp.end())
        mp[A->random]=new RandomListNode(A->random->label);
        if(A->next)
        mp[A]->next=mp[A->next];
        if(A->random)
        mp[A]->random=mp[A->random];
        help->next=mp[A];
        help=help->next;
        A=A->next;
    }
    return ans->next;
}

