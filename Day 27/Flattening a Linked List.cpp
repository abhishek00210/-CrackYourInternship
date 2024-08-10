class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *mergeList(Node *l1,Node *l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        Node *result;
        if(l1->data<l2->data){
            result=l1;
            result->bottom=mergeList(result->bottom,l2);
        }
        else{
             result=l2;
            result->bottom=mergeList(l1,result->bottom);
        }
        result->next=NULL;
        return result;
    }
    Node *flatten(Node *root) {
        // Your code here
        if(!root){
            return NULL;
        }
        Node *head2=flatten(root->next);
        return mergeList(root,head2);
    }
};