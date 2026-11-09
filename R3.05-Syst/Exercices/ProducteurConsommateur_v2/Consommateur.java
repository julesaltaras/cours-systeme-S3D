public class Consommateur extends Thread {
    private DepotCommun depot;
    
    public Consommateur(DepotCommun d) {
        depot = d;
    }
    
    public void run() {
	boolean stop = false;
	long attente_active = 0;
	char c = depot.prendre();
        while ( c != '!' ) {
	    if ( depot.estVide() ) {
		// Grrr... que fait ce Producteur ? Il dort ?
		attente_active++;
	    } else {
		System.out.print(c);
		c = depot.prendre();
	    }
        }
	//System.out.println("Attente active Consommateur = " + attente_active + " :-(");	
    }
}
