class Solution {
private:
    int findLength(ListNode* root) {
        ListNode* head = root;

        int n = 0;
        while( head != NULL ) {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* Next(ListNode* root, int n, int surplus) {
        ListNode *prev = root;
        for( int i = 0 ; i < n ; ++i ) {
            prev = root;
            if( root != NULL ) {
                root = root->next;
            }
        }

        if ( surplus > 0 ) {
            prev = root;
            if( root != NULL ) {
                root = root->next;
            }
        }

        if( prev != NULL && prev->next != NULL) {
            prev->next = NULL;
        }

        return root;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = findLength(head);
        int res = N % k;
        int n = N / k;

        vector<ListNode*> ret;
        ret.reserve(k);

        for( int i = 0 ; i < k; ++i ) {
            ret.push_back(head);
            ListNode* next = Next(head, n, res--);
            head = next;
        }

        return ret;
    }
};
