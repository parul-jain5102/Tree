class Solution
{
    public:
int isBST1(Node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
    int isBSTUtil(Node* node, int min, int max)
{
    if (node==NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return
        isBSTUtil(node->left, min, node->data-1) && 
        isBSTUtil(node->right, node->data+1, max);
}
    bool isBST(Node* node) 
    {
        if(isBST1(node))
          return 1;
        else
         return 0;
    
        
        
    }
};
