package task_4.models;
import task_4.interfaces.Tree;

public class BinarySearchTree<T extends Comparable<T>> implements Tree<T>
{
        private Node<T> rootNode;

        @Override
        public Tree<T> insert(T data)
        {
                this.rootNode = insert(data, this.rootNode);
                return this;
        }

        @Override
        public void delete(T data) { this.rootNode = delete(data, this.rootNode); }

        @Override
        public void traverse() { inOrderTraversal(this.rootNode); }

        @Override
        public T getMaxElement()
        {
                if (this.isEmpty())
                        return null;
                return getMaxElement(this.rootNode);
        }

        @Override
        public T getMinElement()
        {
                if (this.isEmpty())
                        return null;
                return getMinElement(this.rootNode);

        }

        @Override
        public boolean isEmpty() { return this.rootNode == null; }
 
        private T getMinElement(Node<T> node)
        {
                if (node.getLeft() != null)
                        return getMinElement(node.getLeft());
                return node.getData();
        }


        private T getMaxElement(Node<T> node)
        {
                if (node.getRight() != null)
                        return getMaxElement(node.getRight());
                return node.getData();
        }

        private void inOrderTraversal(Node<T> node)
        {
                if (node != null)
                {
                        inOrderTraversal(node.getLeft());
                        System.out.println(node);
                        inOrderTraversal(node.getRight());
                }
        }

        private Node<T> insert(T data, Node<T> node)
        {
                if (node == null)
                        return new Node<T>(data);
                /* Left subtree */
                if (data.compareTo(node.getData()) < 0)
                        node.setLeft(insert(data, node.getLeft()));
                /* Right subtree */
                else if (data.compareTo(node.getData()) > 0)
                        node.setRight(insert(data, node.getRight()));
                return node;
        }

        private Node<T> delete(T data, Node<T> node)
        {
                if (node == null)
                        return null;
                /* Left subtree */
                if (data.compareTo(node.getData()) < 0)
                        node.setLeft(delete(data, node.getRight()));
                /* Right subtree */
                else if (data.compareTo(node.getData()) > 0)
                        node.setRight(delete(data, node.getLeft()));
                else
                        if (node.getLeft() == null)
                                return node.getRight();
                        else if (node.getRight() == null)
                                return node.getLeft();
                        node.setData(getMaxElement(node.getLeft()));
                        node.setLeft(delete(node.getData(), node.getLeft()));
                return node;
        }
}
