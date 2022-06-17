
/**
 * Write a description of WordPlay here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
 
import edu.duke.*;

public class WordPlay {
    public boolean isVowel(char ch){
        char new_ch = Character.toUpperCase(ch);
        
        if (new_ch == 'A' || new_ch == 'E' || new_ch == 'I' || new_ch == 'O' || new_ch == 'U'){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    public String replaceVowels(String phrase, char ch){
        // Make StringBuilder with message
        StringBuilder noVowel = new StringBuilder(phrase);
        
        for (int i=0; i < noVowel.length(); i++){
            char currChar = noVowel.charAt(i);
            boolean isVow = isVowel(currChar);

            if (isVow == true){
                noVowel.setCharAt(i, ch);
            }
           
        }
        return noVowel.toString();
    }
    
    public void test_isVowel(){
        String noVowel = replaceVowels("Hello World",'*');
        System.out.println(noVowel);
    }
}
