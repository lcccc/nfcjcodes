import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			BigDecimal R = in.nextBigDecimal();
			int n = in.nextInt();
			BigDecimal answer = R;
			for(int i = 1; i < n; i ++)
				answer = answer.multiply(R);
			String ans = answer.toPlainString();	//toString is not enough here
			if(ans.charAt(0) == '0' && ans.charAt(1)== '.')
				ans = ans.substring(1, ans.length());
			if(ans.contains("."))
			{
				boolean run = true;
				int numOfZero = 0;
				while(run)
				{
					if(ans.charAt(ans.length() - 1 - numOfZero) == '0')
						numOfZero += 1;
					else if(ans.charAt(ans.length() - 1 - numOfZero) == '.')
					{
						numOfZero += 1;
						run = false;
					}
					else
						run = false;
				}
				System.out.println(ans.substring(0, ans.length() - numOfZero));
			}
			else
				System.out.println(ans);
		}
	}
}