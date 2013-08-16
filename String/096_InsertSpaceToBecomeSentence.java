import java.util.*; 

class InsertSpaceToSentence {
	
	static void spacing(String prefix, String sen, HashMap dict) {

	     if(dict.get(sen)!=null) {
	           System.out.println((prefix + " " + sen).trim());
	     }

	     if(sen.length() <= 1) return;
	     
	     for(int i = 1; i < sen.length(); i++) {
	     
	        String word = sen.substring(0, i);
	        if(dict.get(word)!=null) {
	            spacing(prefix + " " + word, sen.substring(i), dict);
	        }  
	     }
	}

	static void spaceSentence(String sentence, HashMap dict) {
	     if(sentence == null || sentence.length() ==0) return;
	     
	      spacing("", sentence, dict);

	}

	
	public static void main(String[] args) {
		HashMap hm=new HashMap();
		hm.put("I","I");
		hm.put("am","am");
		hm.put("a","a");
		hm.put("Test","Test");
		spaceSentence("IamaTest",hm);
	}
}