import java.util.*;

public class EssaiJava {

    public static void main (String [] args) {
	int val = 10;

	assert(val == 10);
	
	System.out.println("Pour compiler ce programme:");
	System.out.println("   javac EssaiJava.java");

	System.out.println("Pour interpreter:");
	System.out.println("   java -ea EssaiJava");

	System.out.println("Pour compiler ce programme:");
	System.out.println("   javac -g EssaiJava.java");
	System.out.println("puis:");
	System.out.println("   jdb EssaiJava");

	while ( val > 0 ) {
	    val = val - 1;
	}
    }

}
