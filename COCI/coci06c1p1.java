//https://dmoj.ca/problem/coci06c1p1
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);

        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<Integer> check = new ArrayList<>();
        int count = 0;
        

        for (int i = 0; i<10; i++){
            int num = sc.nextInt();
            list.add(num);
        }
        
        for (int i = 0; i<10; i++){
            if (check.contains((list.get(0))%42) == false){
                check.add(list.get(0)%42);
                count++;
            }
            list.remove(0);
        }
        
        System.out.println(count);
        
    }
}