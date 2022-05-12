import edu.duke.*;

/**
 * Write a description of PerimeterRunner here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class PerimeterRunner {
    
    public double getPerimeter(Shape s){
        double totalPerim = 0;
        Point prevPt = s.getLastPoint();
        
        for(Point currPt: s.getPoints()){
            double currDist = prevPt.distance(currPt);
            totalPerim = totalPerim + currDist;
            prevPt = currPt;
           
        }
        return totalPerim;
    }
    
    public double getNumPoints(Shape s){
        
        return points;
    }
    
    public double getAverageLength(Shape s){
        
        return avg_len;
    }
    
    public void testPerimeter(){
        FileResource fr = new FileResource();
        Shape s = new Shape(fr);
        
        double length = getPerimeter(s);
        System.out.println("perimeter= " + length);
        
        double points = getNumPoints(s);
        System.out.println("Number of Points= " + points);
        
        double avg_len = getAverageLength(s);
        System.out.println("Average Length= " + avg_len);
    }
    
    public static void main(String[] args){
        PerimeterRunner pr = new PerimeterRunner();
        pr.testPerimeter();
    }
}
