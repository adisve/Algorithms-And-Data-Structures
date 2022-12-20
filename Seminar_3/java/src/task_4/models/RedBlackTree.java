package task_4.models;

import task_4.interfaces.Tree;

/**
 * Root node must always be black, nodes at lowest 
 * height must be red.
 * Every node is considered a red node when it is first inserted,
 * and all parents of red nodes must be black nodes.
 * 
 * Maintains the balance of the tree by recoloring the nodes,
 * faster operation than rotating a set of nodes. Left-heavy
 * and right-heavy situations require rotations and recolouring.
 */
public class RedBlackTree<T extends Comparable<T>> implements Tree<T>
{

        private Node<T> rootNode;

        @Override
        public Tree<T> insert(T data)
        {
                Node<T> node = new Node<>(data);
                this.rootNode = insert(node, this.rootNode);
                rotateAndRecolor(node);
                return this;
        }

        @Override
        public void delete(T data) { /* stub */ }

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
        
        private Node<T> insert(Node<T> node, Node<T> insertionNode)
        {
                if (insertionNode == null)
                        return insertionNode;
                /* Left subtree */
                if (insertionNode.getData().compareTo(node.getData()) < 0)
                {
                        node.setLeft(insert(node.getLeft(), insertionNode));
                        node.getLeft().setParent(node);
                }
                /* Right subtree */
                else if (insertionNode.getData().compareTo(node.getData()) > 0)
                {
                        node.setRight(insert(node.getRight(), insertionNode));
                        node.getRight().setParent(node);
                }
                return insertionNode;
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
         */
        private void rotateRight(Node<T> node)
        {
                Node<T> leftNode = node.getLeft();
                node.setLeft(leftNode.getRight());

                if (node.getLeft() != null)
                        node.getLeft().setParent(node);
                leftNode.setRight(node);
                leftNode.setParent(node.getParent());
                updateChildrenOfParentNode(node, leftNode);
                node.setParent(leftNode);
        }

        private void updateChildrenOfParentNode(Node<T> node, Node<T> tmpNode)
        {
                /* If this node is root node */
                if (node.getParent() == null)
                        this.rootNode = tmpNode;
                else if (node.isLeft())
                        node.getParent().setLeft(tmpNode);
                else
                        node.getParent().setRight(tmpNode);

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
         */
        private void rotateLeft(Node<T> node)
        {
                Node<T> rightNode = node.getRight();
                node.setRight(rightNode.getLeft());

                if (node.getRight() != null)
                        node.getRight().setParent(node);
                rightNode.setLeft(node);
                rightNode.setParent(node.getParent());
                updateChildrenOfParentNode(node, rightNode);
                node.setParent(rightNode);
        }

        private void rotateAndRecolor(Node<T> node)
        {
                Node<T> parentNode = node.getParent();
                /* If the parent of the node we inserted is a black
                 * node we did not violate the coloring rules for subtrees
                 */
                if (node != this.rootNode && parentNode.getColor() == Color.RED)
                {
                        Node<T> grandParentNode = node.getParent().getParent();
                        Node<T> uncleNode = parentNode.isLeft() ? grandParentNode.getRight() : grandParentNode.getLeft();

                        /* Recolor nodes */
                        if (uncleNode != null && uncleNode.getColor() == Color.RED)
                                recolor(parentNode, uncleNode, grandParentNode);

                        /* Left-heavy tree */
                        else if (parentNode.isLeft())
                                recolorAndRotateRight(node, parentNode, grandParentNode);
                        /* Right-heavy tree */
                        else if (!parentNode.isLeft())
                                recolorAndRotateLeft(node, parentNode, grandParentNode);
                
                }
                this.rootNode.setColor(Color.BLACK);
        }
        
        private void recolorAndRotateRight(Node<T> node, Node<T> parentNode, Node<T> grandParentNode)
        {
                if (!node.isLeft())
                        rotateLeft(parentNode);

                parentNode.flipColor();
                grandParentNode.flipColor();
                rotateRight(grandParentNode);
                rotateAndRecolor(node.isLeft() ? parentNode : grandParentNode);
        }

        private void recolorAndRotateLeft(Node<T> node, Node<T> parentNode, Node<T> grandParentNode)
        {
                if (!node.isLeft())
                        rotateRight(parentNode);

                parentNode.flipColor();
                grandParentNode.flipColor();
                rotateLeft(grandParentNode);
                rotateAndRecolor(node.isLeft() ? grandParentNode : parentNode);
        }

        /**
         * Allows us to move upwards from node we inserted
         * to its grandparent node
         *
         * @param parentNode
         * @param uncleNode
         * @param grandParentNode
         */
        private void recolor(Node<T> parentNode, Node<T> uncleNode, Node<T> grandParentNode)
        {
                uncleNode.flipColor();
                parentNode.flipColor();
                grandParentNode.flipColor();
                rotateAndRecolor(grandParentNode);
        }

}
