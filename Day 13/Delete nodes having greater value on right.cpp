class Solution {
public:
    Node* compute(Node* head) {
        vector<int> v;
        Node* p = head;
        
        // Storing the values of the linked list in a vector
        while (p) {
            v.push_back(p->data);
            p = p->next;
        }
        
        vector<bool> toRemove(v.size(), false); // To keep track of which nodes to remove
        
        // Iterating through the vector to mark nodes for removal
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] > v[i]) {
                    toRemove[i] = true; // Marking node for removal
                    break; // No need to check further
                }
            }
        }
        
        Node* res = new Node(-1); // Dummy node
        Node* t = res;
        
        // Reconstructing the linked list with nodes not marked for removal
        for (int i = 0; i < v.size(); i++) {
            if (!toRemove[i]) {
                Node* temp = new Node(v[i]);
                t->next = temp;
                t = temp;
            }
        }
        
        return res->next; // Returning the head of the new linked list
    }

};