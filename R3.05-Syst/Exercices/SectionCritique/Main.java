public class Main {
    public static void main (String[] args) 
    {
	UnThread unThread1 = new UnThread();
	UnThread unThread2 = new UnThread();
	UnThread unThread3 = new UnThread();
	UnThread unThread4 = new UnThread();
	UnThread unThread5 = new UnThread();
	 
	unThread1.start();
	unThread2.start();
	unThread3.start();
	unThread4.start();
        unThread5.start();

	try {
	    unThread1.join() ;
	    unThread2.join() ;
	    unThread3.join() ;
	    unThread4.join() ;
	    unThread5.join() ;	 
	}
	catch  (InterruptedException e) { }
	System.out.println("");
	System.out.println("Si les affichages ne sont pas alignés.");
	System.out.println("La section n'est pas une section critique.");	
    }
}
