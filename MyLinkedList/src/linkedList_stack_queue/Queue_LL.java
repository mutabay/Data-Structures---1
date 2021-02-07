
package linkedList_stack_queue;


public class Queue_LL<AnyType> {

    
    private SingleLinkedList<AnyType> list;

    public Queue_LL(AnyType toCreate)
    {
        
    }
    
    public SingleLinkedList<AnyType> getList() {
        return list;
    }

    public void setList(SingleLinkedList<AnyType> list) {
        this.list = list;
    }
    
    
}
