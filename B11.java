import java.io.*;
import java.util.*;
class B1{
    static{
        System.loadLibrary("B11");
    }
    private native void add(int a,int b);
    
    private native void sub(int a,int b);

    private native void mult(int a, int b);

    private native void div(int a, int b);

    public static void main(String [] args){
        Scanner sc=new Scanner(System.in);
        int a,b,ch;
        System.out.println("enter value of a :");
        a=sc.nextInt();
        System.out.println("enter value of b:");
        b=sc.nextInt();

        do{
            System.out.println("enter your choice:");
                ch=sc.nextInt();
                switch(ch){
                    case 1:
                    new B1().add(a,b);
                    break;
                    
                    case 2:
                    new B1().sub(a,b);
                    break;

                    case 3:
                    new B1().mult(a,b);
                    break;

                    case 4:
                    new B1().div(a,b);
                    break;

                    default:
                     System.out.println("your choice is wrong");

                }
        
        }while(ch<5);

    }
}
