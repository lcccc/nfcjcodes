import java.util.Scanner;


public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] gw = {"","I","II","III","IV","V","VI","VII","IIX","IX"};
		String[] sw = {"","X","XX","XXX","XL","L","LX","LXX","XXC","XC"};
		String[] bw = {"","C","CC","CCC","CD","D","DC","DCC","CCM","CM"};
		String[] qw = {"","M","MM","MMM"};
		int a;
		String b;
		String sc;
		Scanner cin = new Scanner(System.in);
		a = cin.nextInt();
		b = cin.next();
		//cin.next();
        //sc = cin.next();
      //  System.out.println(b+" "+sc);
		if(b.equals("R") == false){
			int cc;
			String ssc;
			ssc = cin.next();
			cc = Integer.valueOf(ssc, a);
			cc = cin.nextInt(a);
		//	System.out.println(Integer.valueOf(sc) + " " + Integer.valueOf(b));
			System.out.println(Integer.toString(cc,Integer.valueOf(b)).toUpperCase());
		}
		else {
		//System.out.println("a + b + c :"+a+" "+b+" "+c);
			int c;
			c = cin.nextInt(a);
		//	c = Integer.valueOf(sc);
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
