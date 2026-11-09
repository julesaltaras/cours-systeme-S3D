public class DepotCommun {
    private char[] buffer; // Gestion circulaire du buffer.
    private volatile int dispo; // Nombre de char disponibles pour le Consommateur.
    private int iConso; // Indice pour le Consommateur.
    private int iProduct; // Indice pour le Producteur.
    
    public DepotCommun() {
	buffer = new char[15];
	dispo = 0;
	iConso = 0;
	iProduct = 0;
    }
    
    public boolean estVide() {
	return dispo == 0;
    }
    
    public boolean estPlein() {
	return dispo == buffer.length;
    }
    
    public char prendre () {
	synchronized ( this ) {
	    while ( this.estVide() ) {
		try {
		    this.wait();
		}
		catch (InterruptedException e) { }
	    }
	    dispo--;
	    char resultat = buffer[iConso];
	    iConso ++;
	    if ( iConso == buffer.length) {
		iConso = 0;
	    }
	    this.notify();
	    return resultat;
	}
    }
    
    public void deposer (char value) {
	synchronized ( this ) {
	    while ( this.estPlein() ) {
		try {
		    this.wait();
		} catch (InterruptedException e) { }
	    }
	    dispo++;
	    buffer[iProduct] = value;
	    iProduct ++;
	    if ( iProduct == buffer.length) {
		iProduct = 0;
	    }
	    this.notify();
	}
    }
    
}
