import java.util.Scanner;


public class a{

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] gw = {"","I","II","III","IV","V","VI","VII","IIX","IX"};
		String[] sw = {"","X","XX","XXX","XL","L","LX","LXX","XXC","XC"};
		String[] bw = {"","C","CC","CCC","CD","D","DC","DCC","CCM","CM"};
		String[] qw = {"","M","MM","MMM"};
		int a,c;
		String b;
		Scanner cin = new Scanner(System.in);
		a = cin.nextInt();
		b = cin.next();
		//cin.next();
        String sc;
        sc = cin.next();
		
		if(b.equals("R") == false){
			c = Integer.valueOf(sc,Integer.valueOf(b));
			System.out.println(Integer.toString(c, Integer.valueOf(b)).toUpperCase());
		}
		else {
		//System.out.println("a + b + c :"+a+" "+b+" "+c);
		StringBuffer ans = new StringBuffer();
		ans.append(qw[c/1000]);c%=1000;
		ans.append(bw[c/100]);c%=100;
		ans.append(sw[c/10]);c%=10;
		ans.append(gw[c]);
		while(ans.indexOf(b)!=-1)
		{
			ans.replace(ans.indexOf(b), ans.indexOf(b)+1, "R");
		}
		String s = new String(ans);
		//s = s.toUpperCase();
		System.out.println(s.toUpperCase());
	}
	}
}
