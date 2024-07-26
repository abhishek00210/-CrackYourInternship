class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        int num1=0;int num2=0;
         while(first || second)
         {
             if(first)
             {
                 num1=num1*10 +first->data;
                 first=first->next;
                 
             }
              if(second)
             {
                 num2=num2*10 +second->data;
                 second=second->next;
                 
             }
         }
         
         long long ans=num1*num2;
         return ans;
    }
};