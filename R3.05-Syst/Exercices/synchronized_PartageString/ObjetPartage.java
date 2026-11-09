public class ObjetPartage {

    private String valeur = "";

    public ObjetPartage () {
    }
        
    public void concat (String s) {
	String v = valeur; // <-- Recopie dans la pile.
	
	v = v + s;
	// Juste pour perdre du temps... et forcer le changement de contexte.
	for ( int i = 100000000 ; i >= 0 ; i-- ) {
	}
	
	valeur = v; // <-- Recopie dans le tas.
    }
    
    public String toString () {
	return valeur;
    }
}
