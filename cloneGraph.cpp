
UndirectedGraphNode * getCopyNode(map<UndirectedGraphNode *,UndirectedGraphNode *>& mp, UndirectedGraphNode * node){
	UndirectedGraphNode * cloneNode;
	if(mp.find(node)!=mp.end())
		cloneNode=mp[node];
	else{
		cloneNode=new UndirectedGraphNode();
	}
	return cloneNode;
}


void dfsClone(map<UndirectedGraphNode *,UndirectedGraphNode *>& mp, UndirectedGraphNode *node){


}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	map<UndirectedGraphNode *,UndirectedGraphNode *> mp;
	dfsClone(mp,node);
	return mp[node];        
}