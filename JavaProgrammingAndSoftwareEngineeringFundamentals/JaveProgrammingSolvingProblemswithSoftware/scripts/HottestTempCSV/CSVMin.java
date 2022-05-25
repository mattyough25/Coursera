
/**
 * Write a description of CSVMin here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import edu.duke.*;
import org.apache.commons.csv.*;
import java.io.*;

public class CSVMin {
    public CSVRecord getSmallestOfTwo(CSVRecord currentRow, CSVRecord smallestSoFar){
        if(smallestSoFar == null){
                smallestSoFar = currentRow;
            }
            else{
                double currentTemp = Double.parseDouble(currentRow.get("TemperatureF"));
                double smallestTemp = Double.parseDouble(smallestSoFar.get("TemperatureF"));
                if(currentTemp < smallestTemp){
                    smallestSoFar = currentRow;
                }   
            }
        return smallestSoFar;
    }
    
    public CSVRecord coldestHourInFile(CSVParser parser){
        CSVRecord smallestSoFar = null;
        for(CSVRecord currentRow : parser){
            smallestSoFar = getSmallestOfTwo(currentRow, smallestSoFar);
        }
        return smallestSoFar;
    }
    
    public void testcoldestInDay(){
        FileResource fr = new FileResource("nc_weather/2015/weather-2015-01-01.csv");
        CSVRecord smallest = coldestHourInFile(fr.getCSVParser());
        System.out.println("coldest temperature was " + smallest.get("TemperatureF") +
                           " at " + smallest.get("TimeEST"));
    }
}
