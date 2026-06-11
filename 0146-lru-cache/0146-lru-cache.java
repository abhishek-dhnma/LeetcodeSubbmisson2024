class LRUCache {

    private static class lruNode{

        int key;
        int val;
        lruNode next;
        lruNode pre;
        lruNode(){
            next = pre = null;
        }
        lruNode(int key, int val){
            this.key = key;
            this.val = val;
            next = pre = null;
        }

    }

    private int capacity = 0;
    private Map<Integer, lruNode> map = new HashMap<>();;
    private  lruNode head = new lruNode();
    private lruNode tail = new lruNode();

    LRUCache(int capacity){
        this.capacity = capacity;

        head.next = tail;
        tail.pre = head;
    }


    private void remove(lruNode curr){
        lruNode neighbor = curr.next;

        curr.pre.next = neighbor;
        neighbor.pre = curr.pre;

        curr.next  = null;
        curr.pre = null;

    }

    private void addToFront(lruNode curr ){
        lruNode nxt = head.next;

        head.next = curr;
        curr.next = nxt;
        nxt.pre = curr;
        curr.pre = head;
    }

    private void movetofront(lruNode curr){
        remove(curr);
        addToFront(curr);
    }

    public void put(int key, int val){

        if (map.containsKey(key)){
            lruNode node = map.get(key);
            node.val = val;
            movetofront(node);
        }else {
            //  not present

            if(map.size() == capacity){
                // LRU remove

                map.remove(tail.pre.key);
                remove(tail.pre);
            }

            lruNode node = new lruNode(key, val);
            map.put(key, node );

            addToFront(node);
        }

    }


    public int get(int key){

        if(map.containsKey(key)){
            movetofront(map.get(key));
            return map.get(key).val;
        }else {
            return  -1;
        }

    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */