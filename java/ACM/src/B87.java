import java.math.BigInteger;
import java.util.Scanner;


public class B87 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int cs;
		cs = cin.nextInt();
		for(int Cs = 0;Cs < cs;Cs++)
		{
			int bans = 0;
			BigInteger x,bs;
			x = cin.nextBigInteger();
			//StringBuffer s = new StringBuffer();
			for(int len = 1;len <=200; len ++)
			{
				for(int len8 = 0;len8<=len;len8++)
				{
					StringBuffer s = new StringBuffer();
					for(int i=1;i<=len8;i++)
						s.append(8);
					for(int i=len8+1;i<=len;i++)
						s.append(6);
				//	System.out.println("s:  "+s);
					bs = new BigInteger(s.toString());
					if(bs.mod(x).equals(BigInteger.ZERO))
					{
						bans = 1;
						System.out.println(s);
						break;
					}
				}
			if(bans == 1)break;
			}
			if(bans == 0) System.out.println(-1);			
	}
	}
}
