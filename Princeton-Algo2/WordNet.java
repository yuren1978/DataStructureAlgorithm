
import java.util.HashMap;

public class WordNet {

	private final In synsetsIn;
	private final In hypernymsIn;
	private final HashMap<String, Bag<Integer>> synsetMap;
	// constructor takes the name of the two input files
	public WordNet(String synsets, String hypernyms){
		int currentIndex=-1;
		synsetMap=new HashMap<String, Bag<Integer>>();
		synsetsIn=new In(synsets);
		String line;
		while((line=synsetsIn.readLine())!=null ){
			String[] fields = line.split(",");
			String synsetWord=fields[1];
			String[] words=synsetWord.split(",");
			currentIndex = Integer.parseInt(fields[0]);
			for(String word:words){
				if(synsetMap.containsKey(word)){
					Bag<Integer> bag = synsetMap.get(word);
					bag.add(currentIndex);
				}
				else{
					Bag<Integer> bag=new Bag<Integer>();
					bag.add(currentIndex);
					synsetMap.put(word,  bag);
				}
			}
		}
		StdOut.printf("word count %d and max id %d", synsetMap.size(), currentIndex);

		hypernymsIn=new In(hypernyms);
		while((line=hypernymsIn.readLine())!=null){
			String[] fields = line.split(",");
			StdOut.printf(" %s - %s \n", fields[0], fields[1]);
		}
	}

	// the set of nouns (no duplicates), returned as an Iterable
	public Iterable<String> nouns(){
		return null;
	}

	public boolean isNoun(String word){
		return true;
	}

	public int distance(String nounA, String nounB){
		return 1;
	}

	public String sap(String nounA, String nounB){
		return "";
	}

	public static void main(String[] args){
		String synsetFile=args[0];
		String hypernymsFile=args[1];
		//StdOut.printf("file1 = %s and file2= %s ", synsetFile, hypernymsFile);
		WordNet wordNet=new WordNet(synsetFile, hypernymsFile);

	}

}