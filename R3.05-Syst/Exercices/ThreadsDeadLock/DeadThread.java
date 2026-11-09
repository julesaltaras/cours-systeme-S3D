public class DeadThread extends Thread {
    private Lock lock1 = null;
    private Lock lock2 = null;

    public DeadThread (String str, Lock l1, Lock l2) {
        super(str);
	lock1 = l1;
	lock2 = l2;

    }

    public void run () {
	int i = 0;
        while ( true ) {
	    // Notez bien que cette boucle doit durer très longtemps...
	    lock1.m1(getName(), lock2);
	    i++;
	    System.out.println("loop " + i);
	}
    }

}
