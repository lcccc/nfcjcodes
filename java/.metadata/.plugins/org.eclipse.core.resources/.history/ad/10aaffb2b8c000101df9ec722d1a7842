import java.util.*;
import java.math.*;
class test{
	public static void main(String[] args)
	{
		int n,c;
		Scanner cin = new Scanner(System.in);
		c = cin.nextInt();
		for(int cs = 0;cs < c;cs++)
		{
			n = cin.nextInt();
			int min1,min2;
			min1 = cin.nextInt();
			min2 = cin.nextInt();
			if( min1 > min2) {
				int k = min1;min1 = min2;min2 = k;
			}
			for(int i =3;i<=n;i++)
			{
			int tm;
			tm = cin.nextInt();
			if( tm < min1){
				min2 = min1;min1 =tm;
			}
			else if( tm < min2) min2 = tm;
			}
			System.out.println(min2);
		}
	}
}