public class Main {
    /* Warning: because of the garbage collector, one workaround consists in linked objects.
     */
    public static void mallocMax (){
	long total = 0;
	DoubleLink link = null;
	while (true) {
	    total++;
	    if ((total % 10000) == 0) {
		System.out.println ("total=" + total);		
	    }
	    try {
		link = new DoubleLink(null); 
	    } catch (Throwable e) {
		System.out.println ("No more memory.");
		System.out.println ("total " + total);
	    }
	}
    }
    
    public static void main (String [] args){
	mallocMax();
    }
    
}
