
package linkedList_stack_queue;


public class Stack_Arr<AnyType> {
    
    private AnyType[] storedData ;
    private int size;
    private int capacity;
    private int top;
    
   
    
    public Stack_Arr()
    {
        storedData = null;
        size = 0;
        capacity = 0;
        top = 0;
    }
    
    //Parametric Ctor
    public Stack_Arr( AnyType _storedData, int _capacity )
    {
        size = 1;
        capacity = _capacity;
        top = 1;
        storedData = (AnyType[]) new Object[capacity]; //TODO
        storedData[0] = _storedData;
    }
    
    //Accessor Methods

    public AnyType[] getStoredData() {
        return storedData;
    }

    public void setStoredData(AnyType[] storedData) {
        this.storedData = storedData;
    }
    
    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getTop() {
        return top;
    }

    public void setTop(int top) {
        this.top = top;
    }
    
    public boolean IsEmpty()
    {
        return (size == 0);
    }
    
    public boolean IsFull()
    {
        return (size == capacity);
    }
    
    public void Push( AnyType toAdd) throws Exception
    {
        if ( !IsFull() ) 
        {
            storedData[top] = toAdd;
            size++;
            top++;
        }
        else
        {
            throw new Exception("Stack is full");
        }
    }
    
    public void Pop () throws Exception
    {
        if ( IsEmpty() ) 
        {
            throw new Exception("Stack is empty");
        }
        else
        {
            System.out.println(storedData[top -1 ] + " is popped. ");
            --size;
            --top;
        }
    }
    
    public void PrintStack()
    {
        if ( !IsEmpty() ) {
            for (int i = 0; i < size; i++) 
            {
                System.out.println(storedData[i]);
            }
            System.out.println("-------------------------------------");
        }
        
    }
    
    
    
    
}
