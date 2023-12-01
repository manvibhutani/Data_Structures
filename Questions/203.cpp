#include<iostream>
#include<bits/stdc++.h>

 using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        {
            struct ListNode* temp=NULL;
            free(head);
            return temp;
        }
        struct ListNode *cur,*prev;
        for(cur=head,prev=NULL; (cur!=NULL && prev!=NULL); prev=cur,cur=cur->next)
        {
             struct ListNode* temp;
            if(cur->val==val)
            {
               temp=cur;
                prev->next=cur->next;
                cur=cur->next;
                delete temp;
            }
        }
        
        
        return head;
        
    }

struct ListNode* insert(struct ListNode *first,int n)
{
    struct ListNode* new_node;
    
    new_node->val=n;
    new_node->next=first;
    first=new_node;
    return first;
}
void PrintList(struct node* first)
{
    while(first!=NULL)
    {
        printf("%d\n", first->value);
        first=first->next;
    }
}

int main()
{
return 0;
}