
/**
 * Write a description of Strings3 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Strings3 {
    public String twoOccurrences(String stringa, String stringb){
        int first = stringb.indexOf(stringa);
        int last  = stringb.lastIndexOf(stringa);
        
        if(first-last == 0){
            return "false";
        }
        else{
            return "true";
        }
    }
    
    public String lastPart(String stringa, String stringb){
        int first = stringb.indexOf(stringa);
        
        if(first == -1){
            return stringb;
        }
        else{
            int len = stringb.length();
            String last = stringb.substring(first + 1,len);
        
            return last;
        }
        
    }
    
    public void testing(){
        String testa = "l";
        String testb = "Hello";
        System.out.println("String is " + testb + " Finding " + testa);
        String out = twoOccurrences(testa,testb);
        System.out.println(out);
        
        testa = "o";
        testb = "Hello";
        System.out.println("String is " + testb + " Finding " + testa);
        out = twoOccurrences(testa,testb);
        System.out.println(out);
        
        testa = "q";
        testb = "Hello";
        System.out.println("String is " + testb + " Finding " + testa);
        out = twoOccurrences(testa,testb);
        System.out.println(out);
        
        testa = "H";
        testb = "Hello";
        System.out.println("String is " + testb + " Finding " + testa);
        out = lastPart(testa,testb);
        System.out.println("Last Part: " + out);
        
        testa = "x";
        testb = "Hello";
        System.out.println("String is " + testb + " Finding " + testa);
        out = lastPart(testa,testb);
        System.out.println("Last Part: " + out);
    }
}
