
/**
 * Write a description of CaesarCipher here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import edu.duke.*;

public class CaesarCipher {
    private String alphabet;
    private String shiftedAlphabet;
    private int mainKey;
    public CaesarCipher(int key){
        // Write down the alphabet
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Compute the shifted alphabet
        shiftedAlphabet = alphabet.substring(key) + alphabet.substring(0,key);
        
        mainKey = key;
    }
    
    public int[] countLetters(String message){
        String alph = "abcdefghijklmnopqrstuvwxyz";
        int[] counts = new int[26];
        for(int k=0; k < message.length(); k++){
            char ch = Character.toLowerCase(message.charAt(k));
            int dex = alph.indexOf(ch);
            if (dex != -1){
                counts[dex] += 1;
            }
        }
        return counts;
    }
    
    public int maxIndex(int[] vals){
        int maxDex = 0;
        for(int k=0; k < vals.length; k++){
            if (vals[k] > vals[maxDex]){
                maxDex = k;
            }
        }
        return maxDex;
    }
    
    public String encrypt(String input){
        // Make StringBuilder with message
        StringBuilder encrypted = new StringBuilder(input);
        
        for (int i=0; i < encrypted.length(); i++){
            char currChar = encrypted.charAt(i);
            
             // Account for lowercase letters
            if(Character.isLowerCase(currChar) == true){
                String lowerAlphabet = alphabet.toLowerCase();
                String lowerShiftedAlphabet = shiftedAlphabet.toLowerCase();
 
                int idx = lowerAlphabet.indexOf(currChar);
                
                // If currChar is in the alphabet
                if(idx != -1){
                    char newChar = lowerShiftedAlphabet.charAt(idx);
                    encrypted.setCharAt(i, newChar);
                }            
            }
            
            int idx = alphabet.indexOf(currChar);
            if(idx != -1){
                    char newChar = shiftedAlphabet.charAt(idx);
                    encrypted.setCharAt(i, newChar);
                }   

        }
        return encrypted.toString();
    }
    
    public String decrypt(String encrypted){
        CaesarCipher cc = new CaesarCipher(26-mainKey);
        int[] freqs = countLetters(encrypted);
        int maxDex = maxIndex(freqs);
        int dkey = maxDex - 4;
        if (maxDex < 4) {
            dkey = 26 - (4-maxDex);
        }
        return cc.encrypt(encrypted);
    }
    
    public int breakCaesarCipher(String input){
        CaesarCipher cc = new CaesarCipher(26-mainKey);
        int[] freqs = countLetters(input);
        int maxDex = maxIndex(freqs);
        int dkey = maxDex - 4;
        if (maxDex < 4) {
            dkey = 26 - (4-maxDex);
        }
        return dkey;
    }
    
    public void testCaesar(){
        FileResource fr = new FileResource();
        String message = fr.asString();
        System.out.println("Message: "+message);
        
        String encrypted = encrypt(message);
        System.out.println("Encrypted: "+encrypted);
        
        String decrypted = decrypt(encrypted);
        System.out.println("Decrypted: "+decrypted);
        
        int key = breakCaesarCipher(encrypted);
        System.out.println("Key: "+String.valueOf(key));
    }
}
