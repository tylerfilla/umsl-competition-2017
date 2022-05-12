import java.io.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Created by tyler on 5/12/17.
 */
public class prog2 {

    public static void main(String[] args) throws IOException
    {
        if (args.length < 2)
        {
            System.out.println("COMMAND ERROR");
            return;
        }

        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
        } catch (IOException e)
        {
            System.out.println("FILE ERROR");
            return;
        }

        Map<Character, String> dict = new HashMap<Character, String>();

        String line;
        while ((line = reader.readLine()) != null)
        {
            String[] words = line.split("\\W+");

            for (String word : words)
            {
                dict.put(Character.toLowerCase(word.charAt(0)), word);
            }

        }

        String name = args[1];

        Set<Character> used = new HashSet<Character>();

        String finalString = "";

        for (int ci = 0; ci < name.length(); ci++)
        {
            char c = Character.toLowerCase(name.charAt(ci));

            if (!Character.isAlphabetic(c))
            {
                continue;
            }

            if (used.contains(c))
            {
                continue;
            }

            used.add(c);

            finalString += c;
        }

        for (int ci = 0; ci < finalString.length(); ci++)
        {
            char c = Character.toLowerCase(finalString.charAt(ci));

            System.out.print(dict.get(c));

            if (ci < finalString.length() - 1)
            {
                System.out.print(" ");
            }
        }

        reader.close();
    }

}

