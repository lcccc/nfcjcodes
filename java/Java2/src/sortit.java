import java.util.Arrays;
import java.util.Scanner;


public class sortit {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
		String s;
		s = cin.next();
		//System.out.println(s);
		
		s = s.replace('5',' ');
		//	System.out.println(s);
		String sarr[];
		sarr= s.split(" ");
		if(sarr.length == 0) System.out.println("0");
		else {
		int[] arr =new int[sarr.length];
		for(int i = 0;i < sarr.length;i++)
			arr[i] = Integer.valueOf(sarr[i]);
		Arrays.sort(arr);
		for(int i = 0;i < arr.length;i++)
		{
			System.out.print(arr[i]);
			if( i != arr.length -1)
				System.out.println(" ");
			else System.out.println();
		}
		//System.out.println();
	}
		}
	}
}
