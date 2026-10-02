class LRUCache {
public:
    struct node{
        int key;
        int value;
        node *next;
        node *prev;

        node(int k,int v)
        {
            key=k;
            value=v;
        }
    };
    node *head=new node(0,0);  
    node *tail=new node(0,0);

    int cap;

    unordered_map<int,node*> m;


    void addnode(node *temp){
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        
    }

    void deletenode(node *temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }


    LRUCache(int capacity) {
      cap=capacity;
      head->next=tail;
      tail->prev=head;


    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {

            node*temp=m[key];
            
            int x=temp->value;
            m.erase(key);

            deletenode(temp);
            addnode(temp);

            m[key]=head->next;

            return x;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *temp=m[key];
            m.erase(key);
            deletenode(temp);
            cap++;
           
        }

        if(cap<=0){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }else cap--;    

        node *newnode=new node(key,value);
        addnode(newnode);
        m[key]=head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */