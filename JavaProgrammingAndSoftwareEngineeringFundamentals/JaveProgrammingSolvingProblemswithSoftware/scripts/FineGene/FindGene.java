
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
            return "invalid (no start codon)";
        }
        int stopIndex = dna.indexOf("TAA",startIndex + 3);
        if(stopIndex == -1) // not TAA
        {
            return "invalid (no TAA stop codon)";
        }
        result = dna.substring(startIndex, stopIndex + 3);
        
        int rString = result.length() % 3;
        if(rString == 0)
        {
            return result;
        }
        else{
            return "invalid (not multiple of 3)";
        }
    }
    
    public void testFindGeneSimple(){
        String dna = "AATGCGTAATATGGT"; //mult not 3
        System.out.println("DNA strand is " + dna);
        String gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
        dna = "AATGCTAGGGTAATATGGT"; // mult is 3
        System.out.println("DNA strand is " + dna);
        gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
        dna = "TTATAA"; // no ATG
        System.out.println("DNA strand is " + dna);
        gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
        dna = "ATGAAA"; // no TAA
        System.out.println("DNA strand is " + dna);
        gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
        dna = "TTTGGGAAA"; // no ATG or TAA
        System.out.println("DNA strand is " + dna);
        gene = findGeneSimple(dna);
        System.out.println("Gene is " + gene);
        
    }
}
