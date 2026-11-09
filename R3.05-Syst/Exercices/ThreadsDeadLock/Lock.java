public class Lock {
    public Lock () {
    }
    
    public synchronized void m1 (String owner, Lock o2) {
	if (o2 != null) {
	    // System.out.println("Un petit print favorise le changement de contexte...");
	    o2.m2(owner, null);
	}
    }
    
    private synchronized void m2 (String owner, Lock o2) {
	if (o2 != null) {
	    o2.m1(owner, null);
	}
    }
    
}
