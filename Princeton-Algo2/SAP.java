public class SAP{
	// constructor takes a digraph (not necessarily a DAG)
	private final Digraph digraph;	
	private final int vsize;

	public SAP(Digraph G){
		digraph=new Digraph(G);
		vsize=digraph.V();
	}

	// length of shortest ancestral path between v and w; -1 if no such path
	public int length(int v, int w){
		if(v<0 || v>vsize-1)
			throw new java.lang.IllegalArgumentException();
		if(w<0 || w>vsize-1)
			throw new java.lang.IllegalArgumentException();

		BreadthFirstDirectedPaths bfsFromV=new BreadthFirstDirectedPaths(digraph, v);
		BreadthFirstDirectedPaths bfsFromW=new BreadthFirstDirectedPaths(digraph, w);

		int shortest=Integer.MAX_VALUE;
		for(int i=0; i<digraph.V(); i++){			
			if(bfsFromV.hasPathTo(i) && bfsFromW.hasPathTo(i) && (bfsFromV.distTo(i)+bfsFromW.distTo(i)<shortest) )
				shortest=bfsFromV.distTo(i)+bfsFromW.distTo(i);
		}		
		return shortest<Integer.MAX_VALUE?shortest:-1;
	}

	// a common ancestor of v and w that participates in a shortest ancestral path; -1 if no such path
	public int ancestor(int v, int w){
		if(v<0 || v>vsize-1)
			throw new java.lang.IllegalArgumentException();
		if(w<0 || w>vsize-1)
			throw new java.lang.IllegalArgumentException();

		BreadthFirstDirectedPaths bfsFromV=new BreadthFirstDirectedPaths(digraph, v);
		BreadthFirstDirectedPaths bfsFromW=new BreadthFirstDirectedPaths(digraph, w);

		int shortestIndex=-1;
		int shortest=Integer.MAX_VALUE;
		for(int i=0; i<digraph.V(); i++){
			if(bfsFromV.hasPathTo(i) && bfsFromW.hasPathTo(i) && bfsFromV.distTo(i)+bfsFromW.distTo(i)<shortest){
				shortestIndex=i;
				shortest=bfsFromV.distTo(i)+bfsFromW.distTo(i);
			}
		}		
		return shortestIndex;
	}

	// length of shortest ancestral path between any vertex in v and any vertex in w; -1 if no such path
	public int length(Iterable<Integer> v, Iterable<Integer> w){
		int shortest=Integer.MAX_VALUE;
		for (int vi: v) {
			for (int wi : w) {
				if(length(vi, wi)<shortest){
					shortest=length(vi, wi);
				}
			}
		}
		return shortest<Integer.MAX_VALUE?shortest:-1;
	}

	// a common ancestor that participates in shortest ancestral path; -1 if no such path
	public int ancestor(Iterable<Integer> v, Iterable<Integer> w){
		int commonAncestor=-1;
		int shortest=Integer.MAX_VALUE;
		for (int vi: v) {
			for (int wi : w) {
				if(length(vi, wi)<shortest){
					commonAncestor=ancestor(vi, wi);
					shortest=length(vi, wi);
				}
			}
		}
		return commonAncestor;
	}

	// for unit testing of this class (such as the one below)
	public static void main(String[] args){
		In in = new In(args[0]);
    	Digraph G = new Digraph(in);
    	SAP sap = new SAP(G);
    	while (!StdIn.isEmpty()) {
	        int v = StdIn.readInt();
	        int w = StdIn.readInt();
	        int length   = sap.length(v, w);
	        int ancestor = sap.ancestor(v, w);
	        StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);
    	}
	}
}