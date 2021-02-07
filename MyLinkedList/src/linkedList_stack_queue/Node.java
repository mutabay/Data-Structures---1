
package linkedList_stack_queue;


public class Node<AnyType>{

    public Node next;
    public AnyType storedValue;
    
    public Node(AnyType storedValue)
    {
        next = null;
        this.storedValue = storedValue;
    }
    
    
}