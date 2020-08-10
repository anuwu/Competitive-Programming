void inorder (Node *root, Node** head, Node** tail)
{
    if (!root)
        return ;
    else
    {
        Node *r ;
        inorder (root->left, head, tail) ;
        
        if (*head == NULL)
        {
            *head = root ;
            *tail = root ;
        }
        else
        {
            (*tail)->right = root ;
            root->left = *tail ;
            *tail = root ;
        }
        
        inorder (root->right, head, tail) ;
    }
}

Node * bToDLL(Node *root)
{
    if (!root)
        return NULL ;
    
    Node *head, *tail, *tmp ;
    
    head = tail = NULL ;
    inorder (root, &head, &tail) ;
    
    return head ;
}
