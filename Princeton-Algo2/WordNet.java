
import java.util.HashMap;
import java.util.Iterator;

public class WordNet {

	private final In synsetsIn;
	private final In hypernymsIn;
	private final SAP sap;
	private final HashMap<String, Bag<Integer>> synsetMap;
	private final HashMap<Integer, String> indexMap;
	private final Digraph hypernymDiagraph;
	// constructor takes the name of the two input files
	public WordNet(String synsets, String hypernyms){
		int currentIndex=-1;
		synsetMap=new HashMap<String, Bag<Integer>>();
		indexMap=new HashMap<Integer, String>();
		synsetsIn=new In(synsets);
		String line;
		while((line=synsetsIn.readLine())!=null ){
			String[] fields = line.split(",");
			String synsetWord=fields[1];
			String[] words=synsetWord.split(" ");
			currentIndex = Integer.parseInt(fields[0]);
			indexMap.put(currentIndex,synsetWord);
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
		//StdOut.printf("word count %d and max id %d", synsetMap.size(), currentIndex);
		hypernymDiagraph=new Digraph(currentIndex+1);
		hypernymsIn=new In(hypernyms);
		while((line=hypernymsIn.readLine())!=null){
			String[] fields = line.split(",");
			int rootIndex=Integer.parseInt(fields[0]);
			for (int i=1; i<fields.length; i++){
				hypernymDiagraph.addEdge(rootIndex,Integer.parseInt(fields[i]));	
			}
		}

		sap=new SAP(hypernymDiagraph);
	}

	// the set of nouns (no duplicates), returned as an Iterable
	public Iterable<String> nouns(){
		return synsetMap.keySet();   
	}

	// is the word a WordNet noun?
	public boolean isNoun(String word){
		return synsetMap.containsKey(word);
	}

	// distance between nounA and nounB (defined below)
	public int distance(String nounA, String nounB){
		if(!(isNoun(nounA) && isNoun(nounB)))
			throw new java.lang.IllegalArgumentException();

		Bag<Integer> nounAIndexes=synsetMap.get(nounA);
		Bag<Integer> nounBIndexes=synsetMap.get(nounB);

		return sap.length(nounAIndexes,nounBIndexes);
	}

	// a synset (second field of synsets.txt) that is the common ancestor of nounA and nounB
	// in a shortest ancestral path (defined below)
	public String sap(String nounA, String nounB){
		if(!(isNoun(nounA) && isNoun(nounB)))
			throw new java.lang.IllegalArgumentException();

		Bag<Integer> nounAIndexes=synsetMap.get(nounA);
		Bag<Integer> nounBIndexes=synsetMap.get(nounB);

		int ancestorInex=sap.ancestor(nounAIndexes,nounBIndexes);
		return indexMap.get(ancestorInex);

	}

	public static void main(String[] args){
		String synsetFile=args[0];
		String hypernymsFile=args[1];
		//StdOut.printf("file1 = %s and file2= %s ", synsetFile, hypernymsFile);
		WordNet wordNet=new WordNet(synsetFile, hypernymsFile);
		StdOut.println(wordNet.distance("Brown_Swiss","barrel_roll"));
	}

}