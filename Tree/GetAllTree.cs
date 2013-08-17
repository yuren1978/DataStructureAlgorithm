using System;
using System.Collections.Generic;

//firstly we define our simple BinaryTree class
class BinaryTree {
	public int value {get;set;}
	public BinaryTree left {get;set;}
	public BinaryTree right {get;set;}
	//contructor
	public BinaryTree(int k) {
		value = k;
	}
	//we also define an in-order print method
	public void PrintInOrder() {
		inOrderTraversal(this);
		Console.WriteLine();
	}
	private void inOrderTraversal(BinaryTree root) {
		if(root==null) return;
		inOrderTraversal(root.left);
		Console.Write(root.value);
		inOrderTraversal(root.right);
	}
}


class GetAllInOrdersFromPreOrder {
	static void Main(String[] args) {
		//now we test our code, we know from our slides that {1,2,3} preset
		//has in total 5 different BTs thus have 5 different in-order ways!
		int[] testPreOrder = {};
		List<BinaryTree> testResults =
				GetAllTrees(testPreOrder, 0, testPreOrder.Length-1);
		
		//Console.WriteLine(testResults.Count);
				
		foreach(BinaryTree eachFormedBt in testResults){
			if (eachFormedBt!=null) {
				eachFormedBt.PrintInOrder();
			}
		}
	}
	//now we come to think about the key method
	//basically we want choose first value as root and split remaining element into two
	//however, even those splited elements can form MULTIPLE sub-trees, therefore we
	//need a data structure to store all the possible BTs
	//we choose a LIST as it is easy to append/remove/iterate
	//start and end index are used to know the focus window in the preorder array!
	static List<BinaryTree> GetAllTrees(int[] preorder, int start, int end) {
		//we firstly define a return data structure
		List<BinaryTree> returnTrees = new List<BinaryTree>();
		//as a recusrive method, I'd prefer to define the stopping cases!
		//if(start>end || start<0 || end>=preorder.Length) {
		if	(start>end){
			//there can be no trees, return null
			returnTrees.Add(null);
			return returnTrees;
		}
		//if(start==end) {//only one element
		//	returnTrees.Add(new BinaryTree(preorder[start]));
		//	return returnTrees;
		//}
		//otherwise,it's the key part we discussed in our slides, split!
		//notice i starts from -1?! So that means left child can be NULL, a trick I tested ^_^
		//for(int i=-1; i<end-start; i++) {
			//List<BinaryTree> leftChildren = GetAllTrees(preorder, start+1, start+1+i);
			//List<BinaryTree> rightChildren = GetAllTrees(preorder, start+1+i+1, end);

		for(int i=start; i<end+1; i++) {
				List<BinaryTree> leftChildren = GetAllTrees(preorder, start+1, i);
				List<BinaryTree> rightChildren = GetAllTrees(preorder, i+1, end);
		    
		   //now we have to go through a nested loop to assign each left/right to root!
			foreach(BinaryTree eachLeft in leftChildren) {
				foreach(BinaryTree eachRight in rightChildren) {
					BinaryTree tempRoot = new BinaryTree(preorder[start]);//everytime we make a copy of root
					tempRoot.left = eachLeft;
					tempRoot.right = eachRight;
					//do not forget to add to our return LIST!
					returnTrees.Add(tempRoot);
				}
			}
		}
		//and finally do not forget to return the returnTrees list
		return returnTrees;
	}
}

/**
* Please watch at http://www.youtube.com/user/ProgrammingInterview
* Contact: haimenboy@gmail.com
*
*/
