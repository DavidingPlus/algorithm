
/*
  13
  1113
  3113
  132113
  1113122113
  ....
*/

import java.util.Scanner;

public class Main
{
	public static String f(String x)
	{
		String y = "";
		
		char t = x.charAt(0);
		int n = 1;
		
		for(int i=1; i<x.length(); i++){
			char c = x.charAt(i);
			if(c==t) 
				n++;
			else{
				y += n;
				y += t;
				t = c;
				n = 1;
			}
		}

		y += n;
		y += t;
		
		return y;		
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		String s = scan.nextLine();
		
		int n = Integer.parseInt(scan.nextLine());
		
		for(int i=0; i<n; i++) s = f(s);
		
		System.out.println(s);
		
	}
}