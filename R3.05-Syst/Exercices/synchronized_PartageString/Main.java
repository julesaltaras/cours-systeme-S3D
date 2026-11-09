public class Main {
    public static void main (String[] args) {
	ObjetPartage commun = new ObjetPartage();
	EssaiThread fil_1 = new EssaiThread("A", commun);
	EssaiThread fil_2 = new EssaiThread("B", commun);
	
	fil_1.start();
	fil_2.start();
    }
}
