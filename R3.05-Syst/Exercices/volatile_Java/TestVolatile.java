public class TestVolatile extends Thread {

     boolean essayeEncore = true;

    public void run() {
        long compteur=0;
        while (essayeEncore) {
            compteur++;
        }
        System.out.println("Thread fini. compteur=" + compteur);
    }

    public static void main(String[] args) {
        TestVolatile t = new TestVolatile();
        t.start();
	try {
	    Thread.sleep(500); // attente en milli-secondes
	} catch (Exception e)
	    {
	    }
        t.essayeEncore = false;
        System.out.println("essayeEncore vaut maintenant false...");
    }
}
