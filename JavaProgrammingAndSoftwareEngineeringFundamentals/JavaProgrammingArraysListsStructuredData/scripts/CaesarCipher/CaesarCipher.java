
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
            int idx = alphabet.indexOf(currChar);
            // If currChar is in the alphabet
            if(idx != -1){
             char newChar = shiftedAlphabet.charAt(idx);
             encrypted.setCharAt(i, newChar);
            }            
        }
        return encrypted.toString();
    }
    
    public void testCaesar(){
        int key = 17;
        FileResource fr = new FileResource();
        String message = fr.asString();
        String encrypted = encrypt(message, key);
        System.out.println(encrypted);
        String decrypted = encrypt(encrypted, 26-key);
        System.out.println(decrypted);
    }
}
