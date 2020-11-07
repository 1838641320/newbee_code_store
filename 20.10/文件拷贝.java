import java.io.*;
import java.math.*;
// import java.nio.Buffer;
// import java.util.*;

public class Main{
	public static <ty> BigInteger big(ty a){
		return new BigInteger(a.toString());
	}
	public static class Filecopy{
		Filecopy(String sor,String des){
			try {
				BufferedReader in=new BufferedReader(new FileReader(sor));
				BufferedWriter out=new BufferedWriter(new FileWriter(des));
				String a=in.readLine();
				while(a!=null){
					out.write(a);
					out.append('\n');
					a=in.readLine();
				}
				in.close();
				out.close();
			}catch(IOException e) {e.printStackTrace();}
		}
	}
	public static void main(String args[]){
		if(args.length==2) {
			String in=args[0],out=args[1];
			new Filecopy(in,out);
		}
		else System.out.println("file copy faled");
	}
}