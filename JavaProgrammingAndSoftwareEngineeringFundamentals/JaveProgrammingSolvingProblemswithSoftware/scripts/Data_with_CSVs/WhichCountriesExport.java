
/**
 * Write a description of WhichCountriesExport here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import edu.duke.*;
import org.apache.commons.csv.*;
public class WhichCountriesExport {
    public void listExporters(CSVParser parser, String exportOfInterest){
        for(CSVRecord record : parser){
            String export = record.get("Exports");
            if(export.contains(exportOfInterest)){
                String country = record.get("Country");
                System.out.println(country);
            }
        }
    }
    
    public void whoExportsCoffee(){
        FileResource fr = new FileResource();
        CSVParser parser = fr.getCSVParser();
        listExporters(parser, "coffee");
    }
    
    public String countryInfo(CSVParser parser, String country){
        for(CSVRecord record : parser){
            String countries = record.get("Country");
            if(countries.contains(country)){
                String exports = record.get("Exports");
                String value = record.get("Value (dollars)");
                String combine = country+": "+exports+": "+value;
                return combine;
            }
        }
        return "NOT FOUND";
    }
    
    public void listExportersTwoProducts(CSVParser parser, String exportItem1, String exportItem2){
        for(CSVRecord record : parser){
            String export = record.get("Exports");
            if(export.contains(exportItem1)){
                if(export.contains(exportItem2)){
                    String country = record.get("Country");
                    System.out.println(country);
                }
            }
        }
        
    }
    
    public int numberOfExporters(CSVParser parser, String exportItem){
        int num_countries = 0;
        for(CSVRecord record : parser){
            String export = record.get("Exports");
            if(export.contains(exportItem)){
                num_countries = num_countries + 1;
            }
        }
        return num_countries;
    }
    
    public void bigExporters(CSVParser parser, String amount){
        for(CSVRecord record : parser){
            String value = record.get("Value (dollars)");
            if(value.length() > amount.length()){
                String country = record.get("Country");
                System.out.print(country+" ");
                System.out.println(value);
            }
        }
    }
    
    public void tester(){
        // Part 2
        FileResource fr = new FileResource();
        CSVParser parser = fr.getCSVParser();
        String info = countryInfo(parser, "Peru");
        System.out.println(info);
        
        // Part 3
        parser = fr.getCSVParser();
        listExportersTwoProducts(parser,"gold","diamonds");
        // Part 4
        parser = fr.getCSVParser();
        int num = numberOfExporters(parser,"gold");
        System.out.println(num);
        // Part 5
        parser = fr.getCSVParser();
        bigExporters(parser,"$999,999,999");
    }
}
