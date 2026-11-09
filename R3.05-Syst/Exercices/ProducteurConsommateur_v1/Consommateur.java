public class Consommateur extends Thread {
    private DepotCommun depot;
    
    public Consommateur(DepotCommun d) {
        depot = d;
    }
    
    public void run() {
	long attente_active = 0;
	char c = 'x';
        while ( c != '!' ) {
	    if ( depot.estVide() ) {
		// Grrr... que fait ce Producteur ? Il dort ?
		attente_active++;
	    } else {
		c = depot.prendre();
		if (c != '!') {
		    System.out.print(c);
		}
	    }
        }
	// System.out.println("Attente active Consommateur = " + attente_active + " :-(");	
    }
}
