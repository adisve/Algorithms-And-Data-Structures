package task_4.models;

class Node<T extends Comparable<T>> implements Comparable<Node<T>>
{
        private T data;
        private int height = 1;
        private Node<T> left;
        private Node<T> right;

        public Node(T data, Node<T> left, Node<T> right)
        {
                this.data = data;
                this.left = left;
                this.right = right;
        }

        public Node(T data) { this.data = data; }

        public void setRight(Node<T> right){ this.right = right; }

        public void setLeft(Node<T> left){ this.left = left; }

        public void setData(T data) { this.data = data; }

        public void setHeight(int height) { this.height = height; }

        public Node<T> getLeft() { return this.left; }

        public Node<T> getRight() { return this.right; }

        public T getData() { return this.data; }

        public int getHeight() { return this.height; }

        @Override
        public int compareTo(Node<T> other) { return this.getData().compareTo(other.getData()); }

        @Override
        public String toString() { return this.data.toString(); }
}