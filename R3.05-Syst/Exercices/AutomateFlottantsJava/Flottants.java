public class Flottants {
    // Examples de notations autorisées pour les flottants (double).
    public static void main (String[] args) {
	double d = 0;
	
	d = + 5; 
	d = - 5; 
	d = 5; 
	d = 5.0; 
	d = 0.5;
	d = .5;
	d = .5e4;
	d = 5e-1;
	d = 0.5e+1;
	d = 0.5e1;
	d = 5E-1;
	d = 5.E-1;
	d = 0.5E+1;
	d = 0.5E1;
	d = 5.;
	d = 0.;
	d = + .2e6;

	// Celles qui sont rejetées:
	// d = 0.5E +1;
	// d = 0.5E+ 1;
	// d = 0.5E;
	// d = 0.5E+;
	// d = 0 .5;
	// d = . ;
    }
}
