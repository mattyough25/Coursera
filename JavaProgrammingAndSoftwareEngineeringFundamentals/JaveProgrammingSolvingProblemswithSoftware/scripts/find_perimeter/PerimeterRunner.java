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
        double points = 0;
        
        for(Point currPt: s.getPoints()){
            points = points + 1;
        }
        return points;
    }
    
    public double getAverageLength(Shape s){
        double tot_len = 0;
        double num_sides = 0;
        Point prevPt = s.getLastPoint();
        
        for(Point currPt: s.getPoints()){
            double currDist = prevPt.distance(currPt);
            tot_len = tot_len + currDist;
            num_sides = num_sides + 1;
            prevPt = currPt;
        }
        
        double avg_len = tot_len/num_sides;
        return avg_len;
    }
    
    public double getLargestSide(Shape s){
        double large_side = 0;
        Point prevPt = s.getLastPoint();
        
        for(Point currPt: s.getPoints()){
            double currDist = prevPt.distance(currPt);
            if(currDist > large_side){
                large_side = currDist;
            }
            prevPt = currPt;
        }
        return large_side;
    }
    
    public double getLargestX(Shape s){
        double largeX = 0;
        double currX  = 0;
        
        for(Point currPt: s.getPoints()){
            if(currPt.getX() > largeX){
                largeX = currPt.getX();
            }
        }
        return largeX;
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
        
        double large_side = getLargestSide(s);
        System.out.println("Largest Side= " + large_side);
        
        double largeX = getLargestX(s);
        System.out.println("Largest X= " + largeX);
    }
    
    public static void main(String[] args){
        PerimeterRunner pr = new PerimeterRunner();
        pr.testPerimeter();
    }
}
