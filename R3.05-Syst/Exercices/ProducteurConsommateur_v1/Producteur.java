public class Producteur extends Thread {
    private DepotCommun depot;
    
    public Producteur(DepotCommun d) {
        depot = d;
    }
    
    public void run() {
	String ligne = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-abcdefghijklmnopqrstuvwxyz-0123456789-COUCOU\n";
	int nbLignes = 30;
        int i = 0;
	long attente_active = 0;
	while ( nbLignes > 0 ) {
	    if ( depot.estPlein() ) {
		// Grrr... que fait ce Consommateur ? Il dort ?
		attente_active++;
	    } else {
		char c = ligne.charAt(i);
		depot.deposer(c);
		i++;
		if ( i == ligne.length() ) {
		    nbLignes --;
		    i = 0;
		}
	    }
        }
	while ( depot.estPlein() ) {
	    attente_active++;
	}
	depot.deposer('!');
	// System.out.println("Attente active Producteur = " + attente_active + " :-(");
    }

}
