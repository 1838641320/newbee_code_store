import java.io.*;
import java.util.*;
public class Main {	
	public static void main(String args[]) throws Exception {
		StreamTokenizer in=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter out=new PrintWriter(System.out);
		in.nextToken();
		int x=(int)in.nval,xt;
		while(in.ttype!=-1){
			in.nextToken();
			xt=(int)in.nval;
			if(xt<x) {out.print("NO");out.flush();return;}
		}
		out.print("YES");
		out.flush();
		// out.close();
	}
}