class Compare        //Custom Comparator for Determining priority for priority queue (smaller number comes first)
{
public:
    bool operator()(pair<int, ListNode*> &a, pair<int, ListNode*> &b)
    {
        if (a.first != b.first)
            return a.first > b.first;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *head = new ListNode(0);
    ListNode *temp = head;

    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> pq;

    int k = A.size();

    for (int i = 0; i < k; i++)
        pq.push({A[i]->val, A[i]->next});

    while (!pq.empty())
    {
        pair<int, ListNode*> pi = pq.top();
        pq.pop();

        if (pi.second != NULL)
            pq.push({pi.second->val, pi.second->next});

        temp->val = pi.first;
        if (!pq.empty())
        {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
    }

    return head;
}