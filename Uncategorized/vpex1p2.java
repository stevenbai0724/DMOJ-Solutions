//https://dmoj.ca/problem/vpex1p2
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);
        
        int num = sc.nextInt();
        int sum = 0;
        int avg = 0;
        int mistake = 0;
        int array[] = new int[num];
        
        for (int i = 0; i< num; i++){
            array[i] = sc.nextInt();
            sum += array[i];
        }
        
        avg = sum/num;
        
        for (int i = 0; i<num; i++){
            if (array[i] != avg){
                mistake++;
            }
        }
        
        System.out.println(mistake);
        
       
        
        
    }
}