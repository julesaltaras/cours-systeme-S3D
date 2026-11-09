import java.util.*;

public class TestString extends IsTrue {

    // Quelques tests sur la classe String avec d'étranges cas particuliers
    // pour les experts en recherche d'efficacité.

    public static void main (String [] args) {
	String string1 = "toto";
	String string2 = null;

	isTrue(string1 != string2);

	string2 = string1;
	isTrue(string1 == string2);

	string2 = "toto";
	isTrue (string1.equals(string2));
	isTrue(string1 == string2); // Etrange non ?


	string2 = "to" + "to";
	isTrue (string1.equals(string2));
	isTrue(string1 == string2); // Encore plus bizarre non ?

	string2 = "to";
	string2 = string2 + string2;
	isTrue (string1.equals(string2));
	isTrue(string1 == string2); // Ouille ouille...

    }

}
