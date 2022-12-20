package task_4.models;

class Node<T extends Comparable<T>> implements Comparable<Node<T>>
{
        private T data;
        private int height = 1;
        private Color color = Color.RED;
        private Node<T> left;
        private Node<T> right;
        private Node<T> parent;


        public Node(T data) { this.data = data; }

        
        public void setRight(Node<T> right){ this.right = right; }

        public void setLeft(Node<T> left){ this.left = left; }

        public void setData(T data) { this.data = data; }

        public void setHeight(int height) { this.height = height; }

        public void setColor(Color color) { this.color = color; }

        public void setParent(Node<T> parent) { this.parent = parent; }

        public Node<T> getLeft() { return this.left; }

        public Node<T> getRight() { return this.right; }

        public T getData() { return this.data; }

        public int getHeight() { return this.height; }

        public Color getColor() { return this.color; }

        public Node<T> getParent() { return this.parent; }


        public boolean isLeft() { return this == parent.getLeft(); }

        public void flipColor() { this.setColor(color == Color.RED ? Color.BLACK : Color.RED); }



        @Override
        public int compareTo(Node<T> other) { return this.getData().compareTo(other.getData()); }

        @Override
        public String toString() { return this.data.toString(); }
}