public class A
{
	public static void f(int pen, int height)
	{
		String s1 = "";
		for(int i=0; i<pen; i++) s1 += "*";
		String s2 = "";
		for(int i=0; i<height-pen-1; i++) s2 += ".";
		
		String s = s1 + s2 + s1;
		
		s1 = s+'\n';
		s2 = s+'\n'; 
		
		for(int i=0; i<(height-1)/2; i++){
			int m = s.length()/2;
			s = "." + s.substring(0,m-1) + s.substring(m+1) + "."; 
			s1 = s1 + s + "\n";
			if(i==(height-1)/2-1) continue;
			s2 = s + "\n" + s2;
		}
		
		System.out.println(s1 + s2);
	}
	
	public static void main(String[] args)
	{
		String[] ss = new java.util.Scanner(System.in).nextLine().trim().split(" ");
		int pen = Integer.parseInt(ss[0]);
		int height = Integer.parseInt(ss[1]);
		f(pen, height);		
	}
}