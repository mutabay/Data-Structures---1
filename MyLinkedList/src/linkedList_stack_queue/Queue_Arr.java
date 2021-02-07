

package linkedList_stack_queue;


public class Queue_Arr<AnyType> {
    private AnyType[] storedData ;
    private int size,capacity,back,front;
    
    public Queue_Arr(AnyType toCreate ,int capacity)
    {
        this.capacity = capacity;
        //We are adding first element of the queue;
        storedData = (AnyType[]) new Object[capacity];
        storedData[0] = toCreate;
        size = 1;
        back = 1;
        front = 0;
    }
    
    public boolean IsFull()
    {
        return ( size == capacity );
    }
    
    public boolean IsEmpty()
    {
        return ( size == 0 );
    }
    
    public void Enqueue(AnyType toAdd) throws Exception
    {
        if( !IsFull() )
        {
            storedData[back] = toAdd;
            size++;
            back++;
            back = back % capacity;
        }
        else 
        {
            throw new Exception("!!!Queue is full!!!1");
        }
    }
    
    public void Dequeue() throws Exception
    {
        if (!IsEmpty() ) 
        {
            System.out.println(storedData[front] + " is dequeued. ");
            size--;
            front++;
            front = front % capacity;
        }
        
        else  
        {
            throw new Exception("There has no item in the queue");
        }
    }
    
    public void PrintQueue()
    {
        for(int i = 0 ; i < size ;i++ )
        {
            System.out.println(storedData[i]);
        }
    }
    
    
    
    
}
