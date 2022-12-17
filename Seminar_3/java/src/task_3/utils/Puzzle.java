package task_3.utils;

import java.util.HashMap;
import java.util.List;

public class Puzzle {
    
    private int[][] directions = {{0, 1},{1, 0},{-1, 0},{0, -1},{-1, -1},{1, 1},{1, -1},{-1, 1}};
    private HashMap<String, String> prefixes = new HashMap<>();
    private List<String> validWords;
    private String[][] puzzle;

    public Puzzle(String[][] puzzle, List<String> validWords)
    {
        this.puzzle = puzzle;
        this.validWords = validWords;
    }

    /**
     * "The objective is to find the words in the puzzle.
     * These words may be horizontal, vertical, or diagonal in any direction.
     * We can get a big speed increase by storing, in addition to each word W, all of W’s 
     * prefixes. (If one of W’s prefixes is another word in the dictionary, it is stored as a real 
     * word.) Although this may seem to increase the size of the hash table drastically, it does 
     * not, because many words have the same prefixes. When a scan is performed in a 
     * particular direction, if the word that is looked up is not even in the hash table as a prefix, 
     * then the scan in that direction can be terminated early."
     * 
     */
    public void solve()
    {
        this.prefixes = Utils.fill(prefixes, validWords);
        for (int i = 0; i < this.puzzle.length; i++) {
            for (int j = 0; j < this.puzzle[i].length; j++) {
                int[] startCell = {i, j};
                for (int[] neighbour : directions)
                    traverse(startCell, this.puzzle[i][j], neighbour);
            }
        }
    }

    /**
     * Traverse in a certain direction (vertically,
     * diagonally or horizontally) recursively on the
     * basis that the accumulated string is present in
     * the map of valid prefixes
     * 
     * @param cell
     * @param accumulatedString
     * @param direction
     */
    private void traverse(int[] cell, String accumulatedString, int[] direction)
    {
        if (this.prefixes.containsKey(accumulatedString))
        {
            if (Utils.valid(accumulatedString, this.validWords))
                System.out.println("\nWord found! '" + accumulatedString + "'\n");
            int[] nCell = { direction[0] + cell[0], direction[1] + cell[1] };
            if ((nCell[1] < this.puzzle[0].length) && (nCell[1] >= 0))
            {
                if ((nCell[0] < this.puzzle.length) && nCell[0] >= 0)
                {
                    traverse(nCell, accumulatedString + puzzle[nCell[0]][nCell[1]], direction);
                }
            }
        }
    }
}
