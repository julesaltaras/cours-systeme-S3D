public class EssaiThread extends Thread {
    private ObjetPartage commun = null;
    public EssaiThread (String str, ObjetPartage op) {
        super(str);
	commun = op;
    }
    public void run () {
        for ( int i = 5 ; i > 0 ; i-- ) {
            commun.concat(getName());
        }
        System.out.println("Fil" + getName() + ": " + commun.toString());
    }
}
