Node * inOrderSuccessor(Node *root, Node *x)
{
    Node *tmp, *lastleft ;
    
    tmp = x->right ;
    if (tmp)
    {
        while (tmp->left)
            tmp = tmp->left ;
            
        return tmp ;
    }
    
    tmp = root ;
    lastleft = NULL ;
    while (true)
    {
        if (tmp->data == x->data)
            break ;
            
        if (x->data > tmp->data)
            tmp = tmp->right ;
        else
        {
            lastleft = tmp ;
            tmp = tmp->left ;
        }
    }
    
    return lastleft ;
}
