/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * s = head;
        ListNode * f = head;
        bool ok = false;
        while(f!=NULL&&f->next!=NULL)
        {
            f=f->next->next;
            // cout<<f<<endl;
            s=s->next;
            // cout<<s<<endl;
            if(f==s)
            {
                ok=true;
                break;
            }
        }
        // cout<<ok<<endl;
        if(!ok)
            return NULL;
        f=head;
        //here don't use f->next ! = s->next 
        //will give error when tail is connected to head
        while(f!=s)
        {
            f=f->next;
            s=s->next;
        }
        return f;
    }
};