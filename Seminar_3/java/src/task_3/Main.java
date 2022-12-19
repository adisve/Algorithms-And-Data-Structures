package task_3;

import task_3.puzzle.Puzzle;
import task_3.puzzle.Utils;

public class Main {
    public static void main(String[] args)
    {
        Puzzle puzzle = new Puzzle(Utils.lettersGrid(), Utils.wordList());
        puzzle.solve();
    }
}
