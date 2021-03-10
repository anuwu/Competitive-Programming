class Solution {
public:    
    void testvisit(Node* u, unordered_set<int> &vis)
    {
        Node* v ;
        
        printf("%d -> ", u->val) ;
        for (int i = 0 ; i < u->neighbors.size() ; i++)
            printf("%d, ", u->neighbors[i]->val) ;
        printf("\n") ;
        
        vis.insert(u->val) ;
        for (int i=0 ; i<u->neighbors.size() ; i++)
        {
            v = u->neighbors[i] ;
            if (vis.find(v->val) == vis.end())
                testvisit(v, vis) ;
        }
    }
    
    void testdfs(Node* c)
    {
        unordered_set<int> vis ;
        testvisit(c, vis) ;
    }
    
    void dfs(Node* u, Node* cu, unordered_set<int> &vis)
    {
        Node* v ;
                
        vis.insert(u->val) ;
        for (int i=0 ; i<u->neighbors.size() ; i++)
        {
            v = u->neighbors[i] ;
            Node *cv = new Node ;
            cv->val = v->val ;
            cu->neighbors.push_back(cv) ;
            if (vis.find(v->val) == vis.end())
                dfs (v, cv, vis) ;
        }
    }
    
    Node* cloneGraph(Node* node) 
    {
        if (!node)
            return new Node ;
        
        Node* cloned = new Node ;
        unordered_set<int> vis ;
        
        cloned->val = node->val ;
        dfs(node, cloned, vis) ;
        
        testdfs(node) ;   
        printf("\n") ;
        testdfs(cloned) ;
        return cloned ;
    }
};
