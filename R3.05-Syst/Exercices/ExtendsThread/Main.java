public class Main {
    public static void main (String[] args) {
	EssaiThread fil_1 = new EssaiThread("Fil d'execution 1");
	EssaiThread fil_2 = new EssaiThread("Fil d'execution 2");

        System.out.println("On va commencer...");
	// Essayer de commenter la ligne suivante:
	fil_1.start();
        System.out.println("Ca tourne...");
	// Essayer de commenter la ligne suivante:
	fil_2.start();
        System.out.println("Main fini ?");

    }
}
