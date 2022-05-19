
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
        
    }
}
