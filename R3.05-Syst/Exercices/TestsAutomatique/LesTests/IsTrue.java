public class IsTrue {

    public static void isTrue (boolean b) {
	String s = null;
	// Pour activer assert, il faut l'option java -ea
	assert b : "Erreur dans un test.";
	// Remarque: il existe aussi un assert en C ("man 3 assert").
	if (!b) {
	    // Pour assurer une erreur (car s est null):
	    s.concat(s);
	}
    }

}
