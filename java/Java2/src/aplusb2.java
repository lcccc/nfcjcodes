import java.math.BigInteger;
import java.util.Scanner;


public class aplusb2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t;
		t = cin.nextInt();
		//cin.next();
		for(int cs = 1;cs <= t;cs ++)
		{
			BigInteger ba,bb;
			ba = cin.nextBigInteger();
			bb = cin.nextBigInteger();
			System.out.println("Case "+cs+":");
			System.out.println(ba + " + " + bb + " = "+ba.add(bb));
			if( cs != t) System.out.println();
		}
	}

}
