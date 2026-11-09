public class Main {
    public static void main(String[] args) {
        DepotCommun depot = new DepotCommun();
        Consommateur consommateur = new Consommateur(depot);
        Producteur producteur = new Producteur(depot);
	
        producteur.start();
	consommateur.start();
	try {
	    producteur.join();
	    consommateur.join();
        }
        catch  (InterruptedException e) { }
	System.out.println("Commande bash pour tester plusieurs fois:");
	System.out.println("c=1;while true; do c=$((c+1));echo $c;java Main>/tmp/f1;java Main>/tmp/f2;diff /tmp/f1 /tmp/f2;done");
    }
}
