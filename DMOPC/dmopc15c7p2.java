//https://dmoj.ca/problem/dmopc15c7p2
import java.util.*;
import java.io.*;

public class dmopc15c7p2{
    public static void main(String[]args){

        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();
        int count = 1;
        for(int i = 0; i<str.length(); i++){
            if(str.substring(i, i+1).equals(" ")) count++;
        }
        System.out.println(count);
    }
}