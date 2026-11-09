class ThreadPrintDemo implements Runnable {

    private Thread monThread;
    
    public String threadName () {
	return monThread.getName();
    };
    
    Compteur leCompteur;
    
    ThreadPrintDemo(String name,  Compteur c){
	leCompteur = c;
	monThread = new Thread (this, name);
    }

    public void run() {
	int val ;
	do {
	    val = leCompteur.printDown(this);
	} while (val > 0) ;
	System.out.println("Thread " +  this.threadName() + " fini.");
    }
    
    public void start () {
	System.out.println("Commence " +  this.threadName() );
	monThread.start ();
    }

    public void join () {
	try {
	    monThread.join();
	} catch (Exception e) { }
    }
    
}
