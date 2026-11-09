import java.util.*;

public class EssaiFlush {

    public static void main (String [] args) {
	int compteur = 20;
	while ( (compteur--) > 0 ) {
	    System.out.print('1');
	    //System.out.flush();
	    
	    System.err.print('2');
	    //System.err.flush();
	}
	
	compteur = 20;
	while ( (compteur--) > 0 ) {
	    System.out.write('3');
	    //System.out.flush();
	    
	    System.err.write('4');
	    //System.err.flush();
	}
	System.out.flush();
	System.err.flush();
    }
}


