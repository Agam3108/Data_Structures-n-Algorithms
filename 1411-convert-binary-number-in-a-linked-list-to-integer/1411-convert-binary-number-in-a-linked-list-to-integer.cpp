/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int binaryToDec(string binary){
    int n = binary.length();
    int decimal = 0;
     for (int i = 0; i < n; i++) {
        if (binary[n - 1 - i] == '1') {
            decimal += pow(2, i);   
        }
    }
    return decimal;
}
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string binary = "";
        
        while(temp  != NULL){
           binary += to_string(temp->val);
           temp = temp->next;
        }
        int decimalValue = binaryToDec(binary);

        return decimalValue;
    }
};