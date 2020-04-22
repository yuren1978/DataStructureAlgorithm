import java.util.*;

public class FindAnagrams 
{
	public static void main(String[] args)
	{
        List<Integer> index=findAnagrams("cdbaebabacd","abc");
    }
    
    public static List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<Integer>();
        if(s == null || s.length() == 0 || p == null || p.length() == 0) return res;
        int begin = 0, end = 0;
        Map<Character, Integer> map = new HashMap<>();
        for(char c : p.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        int counter = map.size();
        while(end < s.length()){
            char ch = s.charAt(end);
            if(map.containsKey(ch)) {
                map.put(ch, map.get(ch) - 1);
                if(map.get(ch) == 0) {
                    counter--;
                }
            }
            while(counter == 0) {
                if(end - begin + 1 == p.length()) { 
                    res.add(begin);
                }
                char temp = s.charAt(begin);
                if(map.containsKey(temp)) {
                    map.put(temp, map.get(temp) + 1);
                    if(map.get(temp) > 0) {
                        counter++;
                    }
                }
                begin++;
            }
            end++;
        }
        return res;
    }

}