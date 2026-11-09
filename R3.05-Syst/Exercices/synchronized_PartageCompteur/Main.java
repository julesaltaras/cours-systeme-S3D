public class Main {
    
    public static void main(String args[]) {

	Compteur leCompteur = new Compteur(10);
	
	ThreadPrintDemo t1 = new ThreadPrintDemo( "Thread - 1 ", leCompteur );
	ThreadPrintDemo t2 = new ThreadPrintDemo( "Thread - 2 ", leCompteur );
	ThreadPrintDemo t3 = new ThreadPrintDemo( "Thread - 3 ", leCompteur );
	ThreadPrintDemo t4 = new ThreadPrintDemo( "Thread - 4 ", leCompteur );
	
	t1.start();
	t2.start();
	t3.start();
	t4.start();
	
	
	System.out.println("Attente de la fin des 4 threads.");
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	System.out.println("Fin du main.");
	System.out.println("Commande Unix pour regarder les affichages en les triants: \"java Main | grep Counter | sort | more\".");
	System.out.println("Commande Unix pour compter les affichages: \"java Main | grep Counter | wc -l\".");
    }
}
