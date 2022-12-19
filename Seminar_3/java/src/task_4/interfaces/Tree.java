package task_4.interfaces;

public interface Tree<T extends Comparable<T>>
{
        Tree<T> insert(T data);
        
        void delete(T data);
        
        void traverse();
        
        T getMaxElement();
        
        T getMinElement();

        boolean isEmpty();

        
}
