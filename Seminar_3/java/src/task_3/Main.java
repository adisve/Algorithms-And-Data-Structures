package task_3;

import java.util.Arrays;
import java.util.List;

import task_3.utils.Puzzle;

public class Main {
    
    /**
     * Example inputs
     */
    static List<String> words = Arrays.asList("this", "that", "fat", "two");
    static String grid[][] = {
        { "t", "h", "i", "s" },
        { "w", "a", "t", "s" },
        { "o", "a", "h", "g" },
        { "f", "g", "d", "t" }
    };

    public static void main(String[] args)
    {
        Puzzle puzzle = new Puzzle(grid, words);
        puzzle.solve();
    }
}
