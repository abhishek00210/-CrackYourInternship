class Solution
{
    public: 
   void preorder(Node* root, Node*& prev)
    {
        if (root == NULL)
        {
            return;
        }

        // Recur on the left subtree
        preorder(root->left, prev);

        // Process the current node
        Node* newNode = new Node(root->data);

        // If this is the first node, prev will be NULL
        if (prev == NULL)
        {
            prev = newNode;
        }
        else
        {
            // Link the previous node with the current node
            prev->right = newNode;
            newNode->left = prev;

            // Move prev to the current node
            prev = newNode;
        }

        // Recur on the right subtree
        preorder(root->right, prev);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        if(root == NULL)
        {
            return NULL;
        }
         Node* head = NULL;
        Node* prev = NULL;

        // Perform in-order traversal to build the DLL
        preorder(root, prev);

        // Traverse to the head of the doubly linked list
        head = prev;
        while (head && head->left)
        {
            head = head->left;
        }

        return head;
    }
};