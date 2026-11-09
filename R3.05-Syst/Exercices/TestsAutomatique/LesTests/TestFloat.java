import java.util.*;

public class TestFloat extends IsTrue {

    // Les float sont sur 32 bits....

    public static void main (String [] args) {
	String string;

	string = "" +         0.79999992f;
	isTrue(string.equals("0.7999999"));

	string = "" +         0.79999993f;
	isTrue(string.equals("0.79999995"));
    }

}
