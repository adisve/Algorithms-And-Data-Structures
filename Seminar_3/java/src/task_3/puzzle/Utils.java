package task_3.puzzle;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Utils {

	/**
	 * Fill hashmap with occurrances of valid
	 * prefixes based on if they match any element
	 * in the list of valid words
	 * 
	 * @param map
	 * @param validWords
	 * @return
	 */
	public static HashMap<String, String> fill(HashMap<String, String> map, List<String> validWords)
	{
		for (int i = 0; i < validWords.size(); i++)
		{
			String currentword = validWords.get(i);
			int wordLength = currentword.length();
			for (int j = 0; j <= wordLength; j++)
				map.put(currentword.substring(0, j), currentword.substring(0, j));
			}
		return map;
	}

	/**
	 * Check if a string is a real word
	 * 
	 * @param res
	 * @param validWords
	 * @return
	 */
	public static boolean valid(String res, List<String> validWords)
	{
		return validWords.contains(res);
	}

	/**
	 * Create grid of letters based on random
	 * letters chosen from random_letters.txt file
	 * @return
	 */
	public static String[][] lettersGrid()
	{
		List<String> lines = new ArrayList<String>();
		List<String> letters = new ArrayList<String>();
		try {
			Scanner scanner = new Scanner(new File("Seminar_3/java/resources/random_letters.txt"));
			while (scanner.hasNextLine()) {
				lines.add(scanner.nextLine());
			}
			scanner.close();
			for (String line : lines) {
				if (line.length() > 1)
					for (String letter : line.split(""))
						letters.add(letter);
				else
					letters.add(line);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return createLetterGrid(letters);
	}

	/**
	 * Create list of real words from random words file
	 * random_words.txt
	 * @return
	 */
	public static List<String> wordList()
	{
		List<String> validWords = new ArrayList<String>();
		try
		{
			Scanner scanner = new Scanner(new File("Seminar_3/java/resources/random_words.txt"));
			while (scanner.hasNextLine())
			{
				String word = scanner.nextLine();
				if (word.length() >= 3)
					validWords.add(word);
			}
			scanner.close();
			}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		return validWords;
	}

	/**
	 * Create 2d grid of random letters
	 * @param letters
	 * @return
	 */
	private static String[][] createLetterGrid(List<String> letters)
	{
		Random randomizer = new Random();
		String[][] grid = new String[100][100];
		for (int i = 0; i < grid.length; i++)
			for (int j = 0; j < grid.length; j++)
				grid[i][j] = letters.get(randomizer.nextInt(letters.size()));
		return grid;
	}
}
