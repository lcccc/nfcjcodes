import java.math.BigDecimal;
import java.util.Scanner;
public class a811 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,m;
		BigDecimal pa,pb;
		while(true)
		{
			int l ;
			
			n = cin.nextInt();
			m = cin.nextInt();
			if( n == 0 && m == 0 ) break;
			cin.next();
			cin.next();
			if(n > m) l = n;
			else l = m;
			pa = BigDecimal.valueOf(0.5);
			pb = BigDecimal.valueOf(0.5);
			pa = pa.pow(n).multiply(BigDecimal.valueOf(l-n+1));
			pb = pb.pow(m).multiply(BigDecimal.valueOf(l-m+1));
			//System.out.println(pa);
			//System.out.println(pb);
			if(pa.equals(pb))
				System.out.println("Equal");
			if(pa.compareTo(pb)==1) System.out.println("Hamlet");
			if(pa.compareTo(pb)==-1) System.out.println("Equal");
			}
		}
	}
