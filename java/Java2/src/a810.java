import java.math.BigInteger;
import java.util.Scanner;


public class a810 {

	static BigInteger[] p = new BigInteger[10010];
	
	public static int gcd(int a,int b) {
		return b!=0?gcd(b,a%b):a;
	}
	public static long getans(int m,int n)
	{
	//	BigInteger[] p = new BigInteger[10010];
		p[0] = BigInteger.ONE;
		for(int i = 1;i <= n;i++)
			p[i] = p[i-1].multiply(BigInteger.valueOf(m));
		BigInteger count ;
		if(n % 2 == 1)
			count = p[n/2+1].multiply(BigInteger.valueOf(n));
		else
			count = p[n/2].add(p[n/2+1]).multiply(BigInteger.valueOf(n/2));
		for(int i = 1; i <= n; i++)
		{
			count = count.add(p[gcd(i,n)]);
		}
		count=count.divide(BigInteger.valueOf(2*n));
		return Integer.parseInt(count.mod(BigInteger.valueOf(1000000007)).toString());
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int t,ncase = 0;
		for(int i = 1;i<=10000;i++)
			p[i] = new BigInteger("0");
		Scanner cin = new Scanner(System.in);
		t = cin.nextInt();
		for(int T=0 ; T < t;T++)
		{
			int n,m;
			m = cin.nextInt();
			n = cin.nextInt();
			ncase++;
			System.out.println("Case #"+ncase+": "+getans(m,n));		
		}
	}
}
