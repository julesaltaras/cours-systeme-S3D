public class TestIntOverflow extends IsTrue {

    // Test du débordement des "int".

    public static void main (String [] args) {
	int i1, i2, i3;
	
	i1 = 1;
	i2 = 2;
	isTrue( i1 + i2 == 3 );

	i2 = 2147483647;
	isTrue( i1 + i2 == 2147483647 ); // Corrigez ici avec la bonne valeur.
    }

}
