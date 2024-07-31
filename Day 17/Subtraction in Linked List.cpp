class Solution {
public:
int count(Node* head){
    int c=0;
    while(head!=NULL) {
        head=head->next;
        c++;
    }
    return c;
}
Node* remZero(Node* t){
    Node* t1 = t;
    while(t!=NULL && t->data==0){
        t=t->next;
        }
    t1=t;
        return t1;
}
 Node* reverseList(Node* head, int &c) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        Node* prev=NULL, *curr=head, *next=head->next;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next!=NULL) next=next->next;
            c++;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        int c1 = 0, c2 = 0;
        head1 = remZero(head1);
        head2 = remZero(head2);
        if(head1==NULL && head2==NULL) return new Node(0);
        if(head1==NULL) return head2;
        c1 = count(head1);
        c2 = count(head2);
        Node* t1 = head1, *t2 = head2, *ans= new Node(0), *t=ans;;
        if(c1==c2){
            Node *te1 = head1, *te2= head2;
            while(te1!=NULL && te2!=NULL && te1->data == te2->data){
                te1=te1->next;
                te2 = te2->next;
            }
            if(te1!=NULL && te2!=NULL && te1->data < te2->data){
                head1 = t2;
                head2 = t1;
            }
        }
        head1 = reverseList(head1, c1);
        head2 = reverseList(head2, c2);
       
        t1 = head1; t2 = head2;
        int borr = 0;
        if(c1 < c2) {
            head1 = t2;
            head2 = t1;
        }
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data-borr < head2->data){
                ans->next = new Node(10+head1->data-borr-head2->data);
                ans=ans->next;
                borr = 1;
            }else{
                ans->next = new Node(head1->data-head2->data-borr);
                ans=ans->next;
                borr=0;
            }
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=NULL){
                if(head1->data-borr < 0){
                ans->next = new Node(10-borr);
                ans=ans->next;
                borr = 1;
            }else{
                ans->next = new Node(head1->data-borr);
                ans=ans->next;
                borr=0;
            }
            head1=head1->next;
        }
        t->next=reverseList(t->next, c1);
        Node* tp = t->next;
         while(t!=NULL && t->data==0){
            t=t->next;
        }
        tp = t;
        if(tp == NULL) return new Node(0);
        return tp;
    }
};