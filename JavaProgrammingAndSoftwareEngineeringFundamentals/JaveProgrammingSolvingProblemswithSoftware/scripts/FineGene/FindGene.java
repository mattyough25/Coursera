
/**
 * Write a description of FindGene here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class FindGene {
    public String findGeneSimple(String dna){
        String result = "";
        int startIndex = dna.indexOf("ATG");
        if(startIndex == -1) // no ATG
        {
            return "";
        }
        int stopIndex = dna.indexOf("TAA",startIndex + 3);
        if(stopIndex == -1) // not TAA
        {
            return "";
        }
        result = dna.substring(startIndex, stopIndex + 3);
        
        return result;
    }
    
    public void testFindGeneSimple(){
        String dna = "AATGCGTAATATGGT";
        System.out.println("DNA strand is " + dna);
        String gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
        dna = "AATGCTAGGGTAATATGGT";
        System.out.println("DNA strand is " + dna);
        gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
        dna = "TTATAA";
        System.out.println("DNA strand is " + dna);
        gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
    }
}
