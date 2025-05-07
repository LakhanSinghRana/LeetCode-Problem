/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* prev=new Node(-1);
        Node* td=prev;
        Node* temp=head;
        while(temp){
            Node* a=new Node(temp->val);
            td->next=a;
            td=td->next;
            temp=temp->next;
        }
        prev=prev->next;
        td=prev;
        temp=head;
        unordered_map<Node*,Node*> m;
        while(temp){
            m[temp]=td;
            temp=temp->next;
            td=td->next;
        }
        
        for(auto x: m){
            Node* a=x.first;
            Node* d=x.second;
            if(a->random!=NULL){
                Node* r=a->random;
                Node* dp=m[r];
                d->random=dp;
            }
        }
        return prev;
    }
};