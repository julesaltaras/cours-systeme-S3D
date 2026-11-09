public class Point {
    
    private double x;
    
    private double y;
    
    public Point (double vx, double vy) {
	x = vx;
	y = vy;
    }
    
    public double getX () {
	return x;
    }
    
    public double getY () {
	return y;
    }
 
    public void translate (int dx, int dy) {
	x += dx;
	y += dy;
    }

}
