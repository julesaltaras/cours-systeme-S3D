class Compteur {

    private int valeurDuCompteur;
    
    Compteur(int i) {
	valeurDuCompteur = i ;
    }
    
    
    public synchronized int printDown(ThreadPrintDemo t) {
	int v = valeurDuCompteur - 1;
	
	if (v > 0) {
	    System.out.println("Counter = " + v + " (" + t.threadName() +")") ;
	}
	valeurDuCompteur = v;
	return v ;
    }

}
