public class Main {
    public static void main (String[] args) {
	Lock lock1 = new Lock();
	Lock lock2 = new Lock();

	new DeadThread("Fil d'execution 1", lock1, lock2).start();

	new DeadThread("Fil d'execution 2", lock2, lock1).start();

    }
}
