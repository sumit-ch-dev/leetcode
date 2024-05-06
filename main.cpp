#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    ListNode *head = new ListNode(1);

    for (int i = 0; i < 10; i++)
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new ListNode(i);
    }

    for (ListNode *temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->val << " ";
    }
}