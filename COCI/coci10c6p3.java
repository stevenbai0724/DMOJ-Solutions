import java.util.*;

public class coci10c6p3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n+1];

        for(int i=1;i<=n;i++){
            arr[i] = sc.nextInt();
        }
        int sum = 0;
        for(int i=n-1;i>=1;i--){
            if(arr[i+1]>arr[i])continue;

            sum += (arr[i]-arr[i+1]+1);

            arr[i] = arr[i+1]-1;

        }
        System.out.println(sum);
        
    }
}