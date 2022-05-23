
/**
 * Write a description of AllCodons here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import edu.duke.*;
public class AllCodons {
    public int findStopCodon(String dnaStr, int startIndex, String stopCodon){
        int currIndex = dnaStr.indexOf(stopCodon, startIndex+3);
        
        while (currIndex != -1){
            int diff = currIndex - startIndex;
            if(diff % 3 == 0){
                return currIndex;
            }
            else{
                currIndex = dnaStr.indexOf(stopCodon, currIndex+1);
            }
        }
        return -1;
    }
    
    public String findGene(String dna, int where){
        int startIndex = dna.indexOf("ATG", where);
        if (startIndex == -1){
            return "";
        }
        
        int taaIndex = findStopCodon(dna,startIndex,"TAA");
        int tagIndex = findStopCodon(dna,startIndex,"TAG");
        int tgaIndex = findStopCodon(dna,startIndex,"TGA");
        int minIndex = 0;
        if (taaIndex == -1 || (tgaIndex != -1 && tgaIndex < taaIndex)){
            minIndex = tgaIndex;
        }
        else {
            minIndex = taaIndex;
        }
        
        if(minIndex == -1 || (tagIndex != -1 && tagIndex < minIndex)){
            minIndex = tagIndex;
        }
        
        if(minIndex == -1){
            return "";
        }
        return dna.substring(startIndex,minIndex + 3);
    }
    
    public StorageResource getAllGenes(String dna){
        StorageResource geneList = new StorageResource();
        
        int startIndex = 0;
        
        while (true){
            String currentGene = findGene(dna,startIndex);
            if (currentGene.isEmpty()){
                break;
            }
            geneList.add(currentGene);
            startIndex = dna.indexOf(currentGene, startIndex) +
                         currentGene.length();
        }
        return geneList;
    }
   

    public void testFindStop(){
        String dna = "xxxyyyzzzTAAxxxyyyzzzTAAxx";
        int dex = findStopCodon(dna,0,"TAA");
        if(dex != -1) System.out.println("error on 9");
        
        dex = findStopCodon(dna,9,"TAA");
        if(dex != -1) System.out.println("errorr on 21");
        
        dex = findStopCodon(dna,1,"TAA");
        if(dex != -1) System.out.println("errorr on 26");
        
        dex = findStopCodon(dna,0,"TAG");
        if(dex != -1) System.out.println("error on 26 TAG");
        System.out.println("tests finished");
    }
    
    public void testFindGene(){
        String dna = "ATGCCCGGGAAATAACCC";
        //String gene = findGene(dna);
        //if (! gene.equals("ATGCCCGGGAAATAA")){
          //  System.out.println("error");
        //}
        //System.out.println("tests finished");
    }
    
    public void testOn(String dna){
        System.out.println("Testing printAllGenes on " + dna);
        StorageResource genes = getAllGenes(dna);
        for (String g:genes.data()){
            System.out.println(g);
        }
    }
    
    public void test(){
        testOn("ATGATCTAATTTATGCTGCAACGGTGAAGA");
        testOn("");
        testOn("ATGATCATAAGAAGATAATAGAGGGCCATGTAA");
    }
    
}
