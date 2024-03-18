 ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
 
        for(int i=0;i<lists.size();i++){
            if(lists[i])
            pq.push({lists[i]->val,lists[i]});
            }
            ListNode* dummyNode = new ListNode(-1);
            ListNode* temp=dummyNode;
            while(!pq.empty()){
                ListNode* minNode=pq.top().second;
                pq.pop();
                if(minNode->next!=NULL)
                 pq.push({minNode->next->val,minNode->next});
                temp->next=minNode;
                temp=temp->next;
            }
        return dummyNode->next;
    }