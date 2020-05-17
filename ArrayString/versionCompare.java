import java.util.*;

public class versionCompare 
{
    public static int compareVersion(String version1, String version2) {
        String[] v1=version1.split("\\.");
        String[] v2=version2.split("\\.");
        Integer length1=v1.length;
        Integer length2=v2.length;
        Integer i=0, j=0;
        while(i<length1 || j<length2){
            int num1= i<length1? Integer.parseInt(v1[i]):0;
            int num2= j<length2? Integer.parseInt(v2[j]):0;
            if(num1<num2)
                return -1;
            else if(num1>num2)
                return 1;
            i++;
            j++;
        }
        return 0;
    }

    public static void main(String[] args)
	{
		System.out.println(compareVersion("0.1","1.1"));
	}
}