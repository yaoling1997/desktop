import java.util.Scanner;

public class A {

	public static void main(String[] args) {		
		Scanner input= new Scanner(System.in);
		int n= input.nextInt();		
		int []a= new int[10];
		int []b= new int[10];
		int []c= new int[10];
		int i;
		boolean bl= true;
		for (i= 1;i<=n;i++){
			int x= input.nextInt();
			a[x]+= 1;
		}
		for (i= 1;i<=n;i++){
			int x= input.nextInt();
			b[x]+= 1;
		}		
		for (i= 1;i<=5;i++){
			c[i]= a[i]+b[i];
			if (c[i]%2==1)
				bl= false;
		}
		if (bl){
			int ans= 0;
			for (i= 1;i<=5;i++)
				ans+= Math.abs(a[i]-b[i]);
			System.out.println(ans/4);
		}else{
			System.out.println(-1);
		}
	}

}
