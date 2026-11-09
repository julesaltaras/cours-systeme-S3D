public class TestPoint extends IsTrue {

    // Petit test de la classe Point.

    public static void main (String [] args) {
	Point p1 = new Point (1.5, 2.5);

	isTrue (p1.getX() == 1.5);
	isTrue (p1.getY() == 2.5);

	p1.translate(1,1);

	isTrue (p1.getX() == 2.5);
	isTrue (p1.getY() == 3.5);


    }
}
