public class Main {
    public static void main (String[] args) {
	Baguette baguette1 = new Baguette("1");
	Baguette baguette2 = new Baguette("2");
	Baguette baguette3 = new Baguette("3");
	Baguette baguette4 = new Baguette("4");
	Baguette baguette5 = new Baguette("5");

	Philosophe philosophe1 = new Philosophe("1", baguette1, baguette2);
	Philosophe philosophe2 = new Philosophe("2", baguette2, baguette3);
	Philosophe philosophe3 = new Philosophe("3", baguette3, baguette4);
	Philosophe philosophe4 = new Philosophe("4", baguette4, baguette5);
	Philosophe philosophe5 = new Philosophe("5", baguette5, baguette1);

        philosophe1.start();
        philosophe2.start();
        philosophe3.start();
        philosophe4.start();
        philosophe5.start();
    }
}
