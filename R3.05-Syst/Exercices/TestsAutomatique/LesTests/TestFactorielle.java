public class TestFactorielle extends IsTrue {

    public static void main (String [] args) {
	
	isTrue( factorielle_v1(1) == 1);

	isTrue( factorielle_v1(2) == 2);

	isTrue( factorielle_v1(3) == 6);

	isTrue(factorielle_v1(11) == 39916800);
	
	isTrue(factorielle_v1(12) == 479001600);
	
	isTrue(factorielle_v1(13) == 1932053504);
	isTrue(factorielle_v2(13) == 6227020800L);
	
    }

    public static int factorielle_v1 (int n) {
	// Version de factorielle avec le type int (32 bits en Java).
	int r = 1;
	int i = 2;
	while (i <= n) {
	    r = i * r;
	    i++;
	}
	return r;
    }
    
    public static long factorielle_v2 (long n) {
	// Version de factorielle avec le type int (64 bits en Java).
	long r = 1;
	long i = 2;
	while (i <= n) {
	    r = i * r;
	    i++;
	}
	return r;
    }

}
