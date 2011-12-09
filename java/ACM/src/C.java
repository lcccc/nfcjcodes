import java.math.*;
import java.util.Scanner;
import java.io.*;
public class C {

	/**
	 * @param args
	 */

	public static void main(String[] args) {
		BigInteger[] f = new BigInteger[55];
		f[1] = new BigInteger("1");
		f[0] = new BigInteger("1");
		for(int i = 2; i <= 51;i ++)
			f[i] = f[i-1].multiply(new BigInteger(Integer.toString(i)));
		
		try{
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n,k;
				n = cin.nextInt();
				k = cin.nextInt();
		//System.out.println(n);
		BigInteger fz,fm,ans;
		fz = new BigInteger("0");
		fm = new BigInteger("1");
		int ct = 0;
		for(int i = 1;i< k+1 && i<=n ;i+=2)
		{
			fz =  fz.add(f[n-i].multiply(f[ct]));
			ct+=2;
		//	System.out.println(fz);
		}
		fm = f[n];
		//System.out.println(fm);
		//for(int i = 1; i<=n;i++)
		//	fm = fm.multiply(new BigInteger(Integer.toString(i)));
		BigInteger big = fm.gcd(fz);
		//System.out.println(fm);
		//System.out.print(" ");
		//System.out.println(big);
		System.out.print(fz.divide(big));
		System.out.print("/");
		System.out.println(fm.divide(big));
		}
		}catch(Exception e)
		{
			return ;
		}
		}
	}

