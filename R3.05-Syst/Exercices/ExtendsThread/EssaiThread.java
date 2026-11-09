public class EssaiThread extends Thread {
    public EssaiThread (String str) {
        super(str);
    }
    public void run () {
        for ( int i = 10 ; i >= 0 ; i-- ) {
            System.out.println(getName() + ": " + i);
            try {
                sleep((long)(Math.random() * 1000));
            } catch (InterruptedException e) {}
        }
        System.out.println(getName() + ": Fin");
    }
}
