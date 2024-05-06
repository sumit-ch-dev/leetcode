#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *curr = head;

        // push all the nodes in the stack
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->next;
        }

        // pop the first node from the stack and set it as the max value
        // create a new list with this node
        curr = st.top();
        st.pop();
        int maxVal = curr->val;
        ListNode *res = new ListNode(maxVal);

        // pop the rest of the nodes and check if the value is greater than the max value
        while (!st.empty())
        {
            curr = st.top();
            st.pop();

            // if the value is less than the max value, skip this node
            if (curr->val < maxVal)
            {
                continue;
            }
            else
            // otherwise create a new node with this value and set it as the max value
            //  the linked list is created in reverse order
            //  so the new node is added at the beginning
            //  and the new node becomes the max value
            //  the max value is updated
            //  the new node is added to the beginning of the list
            {
                ListNode *newNode = new ListNode(curr->val);
                newNode->next = res;
                res = newNode;
                maxVal = curr->val;
            }
        }

        return res;
    }
};

int main()
{
    int nodes[5] = {40, 12, 10, 5, 7};

    // create a linked list from this array

    ListNode *head = new ListNode(nodes[0]);
    ListNode *curr = head;

    for (int i = 1; i < 5; i++)
    {
        ListNode *newNode = new ListNode(nodes[i]);
        curr->next = newNode;
        curr = newNode;
    }

    // we have to remove every node which has a node with a greater value on its right

    // pass the head node to the function
    Solution sol;

    ListNode *newHead = sol.removeNodes(head);

    // print the new list

    while (newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}