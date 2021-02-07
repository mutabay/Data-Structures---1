
package linkedList_stack_queue;

public class Stack_LL<AnyType> {
    private SingleLinkedList<AnyType> list ;

    public SingleLinkedList<AnyType> getList() {
        return list;
    }

    public void setList(SingleLinkedList<AnyType> list) {
        this.list = list;
    }
    
    public Stack_LL(AnyType toCreate)
    {
        list = new SingleLinkedList(toCreate);
    }
    
    public boolean IsEmpty()
    {
        return ( list.IsEmpty() );
    }
    
    public void Push(AnyType toAdd)
    {
        //Adding item front of the head
        Node newNode = new Node(toAdd);
        
        if ( null == list.getHead() ) 
        {
            list.setHead(newNode);
        }
        else 
        {
            newNode.next = list.getHead();
            list.setHead(newNode);
        }        
    }
    
    public void Pop() throws Exception
    {
        //Deleting head item >
        if (null == list.getHead()) 
        {
            throw new Exception("There is not exist stored value");
        }
        
        else 
        {
            Node temp = list.getHead();
            list.setHead(list.getHead().next);
            temp.next = null;
            temp.storedValue = null;
            temp = null;
        }    
    }
    
    public void PrintStack()
    {
        list.PrintSll(); //head to last node
    }
    
    
}
