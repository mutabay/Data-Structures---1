
package linkedList_stack_queue;


public class SingleLinkedList<AnyType>{
    
    private Node head;
    private Node lastNode;
    
    //Accessor Methods
    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    public Node getLastNode() {
        return lastNode;
    }

    public void setLastNode(Node lastNode) {
        this.lastNode = lastNode;
    }
    
    //Parametric Ctor
    public SingleLinkedList(AnyType toCreate)
    {
        System.out.println("Please enter first element of the list");
        head = new Node(toCreate);
        lastNode = head;   
    }
    
    public void Clear()
    {
        head.storedValue = null;
        head.next = null;
        lastNode = head;
    }
    
    public int Size()
    {
        Node currentNode = head;
        int counter = 0;
        while(null != currentNode)
        {
            counter ++;
            currentNode = currentNode.next;
        }
        System.out.println("Size =>"+counter);
        return counter;
    }
    
    public boolean IsEmpty()
    {
        if(null == head)
        {
            return true;
        }
        return false;
    }
    
    public void InsertToEnd(AnyType toAdd)
    {
        Node newNode = new Node(toAdd);
        if(null == head)
        {
            head = newNode;
        }
        
        else 
        {
            lastNode.next = newNode;
            lastNode = newNode;
        }
    }
    
    public void DeleteLastNode() throws Exception
    {
        Node currentNode = head;
        
        if (null == head) 
        {
            throw new Exception("There has no node in the list");
        }
        
        else if ( null == head.next )
        {
            head.storedValue = null;
            head = null;
        }
        
        else 
        {
            while ( null != currentNode.next.next  )
            {
                currentNode = currentNode.next;
            }
            currentNode.next.storedValue = null;
            currentNode.next = null;
        }
        
    }
    
    public void PrintSll()
    {
        Node currentNode = head;
        while (null != currentNode)
        {
            System.out.println(currentNode.storedValue + "\n");
            currentNode = currentNode.next;
        }
        
    }
    
    
    
}
