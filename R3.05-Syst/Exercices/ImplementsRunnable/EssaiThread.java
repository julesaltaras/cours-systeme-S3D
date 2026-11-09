public class EssaiThread implements Runnable {
    private Thread myThread = null;

    public EssaiThread (String str) {
        myThread = new Thread(this, str);
    }
    
    public void start() {
	myThread.start();
    }

    public void run () {
        for ( int i = 10 ; i >= 0 ; i-- ) {
            System.out.println(myThread.getName() + ": " + i);
            try {
                myThread.sleep((long)(Math.random() * 1000));
            } catch (InterruptedException e) {}
        }
        System.out.println(myThread.getName() + ": Fin");
    }
}
