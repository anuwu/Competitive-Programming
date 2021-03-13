class LRUCache {
public:
    typedef class _Node
    {
    public :
        int key ;
        int val ;
        _Node* next ;
        _Node* prev ;
        
        _Node(int key, int val)
        {
            this->key = key ;
            this->val = val ;
            this->next = NULL ;
            this->prev = NULL ;
        }
    } Node ;
    
    typedef class _DLL
    {
    public :
        Node* head ;
        Node* tail ;
        int length ;
        
        _DLL()
        {
            this->head = NULL ;
            this->tail = NULL ;
            this->length = 0 ;
        }
        
        void add(int key, int val)
        {
            Node *ptr = new Node(key, val) ;
            if (!this->head)
                this->head = this->tail = ptr ;
            else
            {
                ptr->next = this->head ;
                this->head->prev = ptr ;
                this->head = ptr ;
            }
            
            this->length++ ;
        }
        
        void remove(Node* rem)
        {
            if (!rem)
                return ;
            
            Node *prv, *nex ;
            prv = rem->prev ;
            nex = rem->next ;
            // printf("\t\tRemoving %d and prv=%d, nex=%d\n", rem->key, prv?prv->key:0, nex?nex->key:0) ;
            if (prv)
                prv->next = nex ;
            else
                this->head = nex ;
            
            if (nex)
                nex->prev = prv ;
            else
                this->tail = prv ;
            
            this->length-- ;
        }
        
        void print()
        {
            Node *ptr = this->head ;
            printf("\t") ;
            while (ptr)
            {
                printf("(%d, %d)%s", ptr->key, ptr->val, ptr->next ? " --> " : "") ;
                ptr = ptr->next ;
            }
            printf("\n") ;
        }
        
    } DLL ;
    
    int capacity ;
    unordered_map<int, Node*> mp ;
    DLL dll ;
    
    LRUCache(int capacity) 
    {
        this->capacity = capacity ;
    }
    
    int get(int key)
    {
        // printf("Getting %d\n", key) ;
        int ret ;
        if(mp.find(key) == mp.end())
            ret = -1 ;
        else
        {
            Node *retnode ;
            retnode = mp[key] ;
            
            this->dll.remove(retnode) ;
            // printf("\tRemoved %d\n", key) ;
            this->dll.add(retnode->key, retnode->val) ;
            // printf("\tAdded %d\n", key) ;
            mp[key] = this->dll.head ;
            ret = retnode->val ;
            delete retnode ;
        }
        
        // this->dll.print() ;
        return ret ;
    }
    
    void put(int key, int val)
    {
        // printf("Putting %d\n", key) ;
        
        Node *delnode = NULL ;
        if (this->mp.find(key) != this->mp.end())
            delnode = this->mp[key] ;
        else if (this->dll.length == this->capacity)
            delnode = this->dll.tail ;
        
        if (delnode)
        {
            this->mp.erase(this->mp.find(delnode->key)) ;
            this->dll.remove(delnode) ;
            // printf("\tRemoved %d\n", delnode->key) ;
            delete delnode ;
        }
        
        this->dll.add(key, val) ;
        // printf("\tAdded %d\n", key) ;
        this->mp[key] = this->dll.head ;
        // this->dll.print() ;
    }
};