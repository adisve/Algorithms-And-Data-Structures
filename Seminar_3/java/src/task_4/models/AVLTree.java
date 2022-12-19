package task_4.models;

import task_4.interfaces.Tree;

public class AVLTree<T extends Comparable<T>> implements Tree<T>
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
                else
                        return node;
                updateHeight(node);
                return rotate(node);
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
                updateHeight(node);
                return rotate(node);
        }

        private void updateHeight(Node<T> node)
        {
                node.setHeight(Math.max(
                        height(node.getLeft()), 
                        height(node.getRight())) + 1);
        }

        private Node<T> rotate(Node<T> node)
        {
                int balance = balance(node);
                /* Left-heavy tree */
                if (balance > 1)
                {
                        if (balance(node.getLeft()) < 0)
                                node.setLeft(rotateLeft(node.getLeft()));
                        return rotateRight(node);
                }
                /* Right-heavy tree */
                if (balance < -1)
                {
                        if (balance(node.getRight()) > 0)
                                node.setLeft(rotateRight(node.getRight()));
                        return rotateLeft(node);
                }
                return node;
        }

        /**
         * Moves left child node of parent to the
         * position of the current parent node,
         * moving the parent node to the right
         * position in the subtree. Setters in
         * rotate() function update the parents parent
         * node so it stays up to date.
         * 
         * @param node
         * @return Child node that succeeds previous
         * parent node
         */
        private Node<T> rotateRight(Node<T> node)
        {
                Node<T> leftNode = node.getLeft();
                Node<T> parentNode = leftNode.getRight();
                leftNode.setRight(node);
                node.setLeft(parentNode);

                updateHeight(node);
                updateHeight(leftNode);

                return leftNode;
        }

        /**
         * Moves right child node of parent to the
         * position of the current parent node,
         * moving the parent node to the left
         * position in the subtree. Setters in
         * rotate() function update the parents parent
         * node so it stays up to date.
         * 
         * @param node
         * @return Child node that succeeds previous
         * parent node
         */
        private Node<T> rotateLeft(Node<T> node)
        {
                Node<T> rightNode = node.getRight();
                Node<T> parentNode = rightNode.getLeft();
                rightNode.setLeft(node);
                node.setRight(parentNode);

                updateHeight(node);
                updateHeight(rightNode);

                return rightNode;
        }
        
        /* bf = hl - hr */
        private int balance(Node<T> node) { return node != null ? height(node.getLeft()) - height(node.getRight()) : 0; }

        private int height(Node<T> node) { return node != null ? node.getHeight() : 0; }
}
