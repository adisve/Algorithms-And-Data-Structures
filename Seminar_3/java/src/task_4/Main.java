package task_4;

import task_4.models.AVLTree;

public class Main
{
        public static void main(String[] args)
        {
                AVLTree<Integer> avlTree = new AVLTree<>();
                avlTree.insert(12);
                avlTree.insert(34);
                avlTree.insert(3);
                avlTree.insert(1);
                avlTree.insert(2);
                avlTree.insert(0);
                avlTree.insert(6);
                avlTree.traverse();
        }
}
