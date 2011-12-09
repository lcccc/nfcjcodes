import java.math.BigInteger;
import java.util.Scanner;


public class npow {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext())
		{
			int n;
			BigInteger ans = new BigInteger("1");
			
			n = cin.nextInt();
			for(int i = 2; i <= n;i++)
				ans = ans.multiply(BigInteger.valueOf(i));
			System.out.println(ans);
		}
		
	}

}
