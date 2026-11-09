public class UnThread extends Thread {
    
    public UnThread () {
    }
    
    public void run() {
	UneClasse une = new UneClasse();
	une.laMethode();
	une.laMethode();
	une.laMethode();
    }
}
