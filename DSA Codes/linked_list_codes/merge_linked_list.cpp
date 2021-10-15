#include <iostream>
#include <stdio.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

void display(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << "-";
        ptr = ptr->next;
    }
    cout << "\n";
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *p = l1;
    ListNode *q = l2;
    if (p == NULL)
    {
        return q;
    }
    if (q == NULL)
    {
        return p;
    }
    ListNode *ptr;
    if (p->val < q->val)
    {
        ptr = p;
        p = ptr->next;
    }
    else
    {
        ptr = q;
        q = ptr->next;
    }
    ListNode *ans = ptr;
    while (p != NULL and q != NULL)
    {
        if (p->val < q->val)
        {
            ptr->next = p;
            ptr = p;
            p = ptr->next;
        }
        else
        {
            ptr->next = q;
            ptr = q;
            q = ptr->next;
        }
    }
    if (p == NULL)
    {
        ptr->next = q;
    }
    if (q == NULL)
    {
        ptr->next = p;
    }
    return ans;
}

int main()
{
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *second = new ListNode();
    ListNode *third = new ListNode();
    ListNode *fourth = new ListNode();
    ListNode *x = new ListNode();
    ListNode *y = new ListNode();

    // creation
    l1->val = 10;
    l1->next = second;

    second->val = 30;
    second->next = third;

    third->val = 40;
    third->next = fourth;

    fourth->val = 80;
    fourth->next = NULL;

    l2->val = 20;
    l2->next = x;

    x->val = 50;
    x->next = y;

    y->val = 60;
    y->next = NULL;

    display(l1);
    display(l2);

    ListNode *ans = new ListNode();
    ans = merge(l1, l2);
    display(ans);

    return 0;
}
