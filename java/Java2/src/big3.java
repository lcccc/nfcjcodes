import java.math.BigInteger;
import java.util.Scanner;


public class big3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n;
		n = cin.nextInt();
		for(int cs = 0;cs < n;cs ++)
		{
			BigInteger ans = new BigInteger("0");
			BigInteger a;
			while(true)
			{
				a = cin.nextBigInteger();
				if( a.equals(BigInteger.ZERO))
					break;
				ans = ans.add(a);
			}
			System.out.println(ans);
			if(cs!= n-1) System.out.println();
		}
	}

}
