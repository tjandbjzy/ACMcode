#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>

typedef long long ll;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode headAns(0);
        ListNode* tempAns = &headAns, tempNode;
        int c = 0;
        while(l1 && l2){
            tempAns = l1 -> val + l2 -> val + c;
            if(tempAns >= 10){
                tempAns -= 10;
                c = 1;
            }else{
                c = 0;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
            tempNode = (ListNode*)malloc(sizeof(ListNode));
            tempAns -> next = tempNode;
            tempAns = tempAns -> next;
        }
        if(l1){
            tempAns -> next = l1;
        }else{
            tempAns -> next = l2;
        }
        return headAns;
    }
};

int main(){
    
    return 0;
}
