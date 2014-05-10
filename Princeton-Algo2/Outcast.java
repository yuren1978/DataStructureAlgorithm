public class Outcast{
	// constructor takes a WordNet object
	private final WordNet wNet;

	public Outcast(WordNet wordnet){
		wNet=wordnet;
	}

	private int getOutCast(String noun, String[] nouns){
		int distance=0;
		for (String otherNoun:nouns) {
			if(noun!=otherNoun){				
				distance+=wNet.distance(noun,otherNoun);
			}
		}
		return distance;
	}

	// given an array of WordNet nouns, return an outcast
	public String outcast(String[] nouns){
		String outCastNoun="";
		int distance=Integer.MIN_VALUE;
		for(String noun: nouns){
			int outCastValue=getOutCast(noun,nouns);
			//StdOut.println(outCastValue);
			if(outCastValue>distance){
				outCastNoun=noun;
				distance=outCastValue;
			}
		}
		return outCastNoun;
	}

	// for unit testing of this class (such as the one below)
	public static void main(String[] args){
		WordNet wordnet = new WordNet(args[0], args[1]);
    	Outcast outcast = new Outcast(wordnet);
	    for (int t = 2; t < args.length; t++) {
	        In in = new In(args[t]);
	        String[] nouns = in.readAllStrings();
	        //StdOut.println(args[t] + ": " + outcast.outcast(nouns));
	    }
	}
}