
/**
 * Write a description of CaesarCipher here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import edu.duke.*;

public class CaesarCipher {
    public String encrypt(String input, int key){
        // Make StringBuilder with message
        StringBuilder encrypted = new StringBuilder(input);
        // Write down the alphabet
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Compute the shifted alphabet
        String shiftedAlphabet = alphabet.substring(key) + alphabet.substring(0,key);
        
        for (int i=0; i < encrypted.length(); i++){
            char currChar = encrypted.charAt(i);
            
            // Account for lowercase letters
            if(Character.isLowerCase(currChar) == true){
                String lowerAlphabet = alphabet.toLowerCase();
                String lowerShiftedAlphabet = shiftedAlphabet.toLowerCase();
                System.out.println(lowerAlphabet);
                int idx = lowerAlphabet.indexOf(currChar);
                
                // If currChar is in the alphabet
                if(idx != -1){
                    char newChar = lowerShiftedAlphabet.charAt(idx);
                    encrypted.setCharAt(i, newChar);
                }            
            }
            
            int idx = alphabet.indexOf(currChar);
                
            // If currChar is in the alphabet
            if(idx != -1){
            char newChar = shiftedAlphabet.charAt(idx);
            encrypted.setCharAt(i, newChar);
            }            

        }
        return encrypted.toString();
    }
    
}
