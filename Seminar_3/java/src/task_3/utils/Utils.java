package task_3.utils;

import java.util.HashMap;
import java.util.List;

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
}
