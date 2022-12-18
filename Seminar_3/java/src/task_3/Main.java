package task_3;

import task_3.utils.Puzzle;
import task_3.utils.Utils;

public class Main {
    public static void main(String[] args)
    {
        Puzzle puzzle = new Puzzle(Utils.lettersGrid(), Utils.wordList());
        puzzle.solve();
    }
}
