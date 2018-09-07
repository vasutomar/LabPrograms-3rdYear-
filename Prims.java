import java.util.*;

class Prims {

	int nodes;
	int edges;
	int MSTsum;
	int[][] mat = new int[100][100]; 
	int infinity = Integer.MAX_VALUE;

	ArrayList<Integer> finalized = new ArrayList<Integer>();
	int[] node_dist = new int[100];
	int[] edge_list = new int[100];	

	Prims() {
		MSTsum = 0;
		nodes = 0;
		init();
	}

	private void init() {
		int i,j,to,from,weight;
		Scanner s = new Scanner(System.in);

		System.out.print("Enter nodes in graph = ");
		nodes = s.nextInt();

		System.out.print("Enter edges in graph = ");
		edges = s.nextInt();

		for(i=0;i<nodes;i++) {
			for(j=0;j<nodes;j++) {
				mat[i][j] = -1;
			}
		}

		for(i=0;i<edges;i++) {
			to = s.nextInt();
			from = s.nextInt();
			weight = s.nextInt();

			mat[to][from] = weight;
			mat[from][to] = weight;
		}
		
		for(i=0;i<nodes;i++) {
			edge_list[i] = -1;
			node_dist[i] = infinity;
		}
		node_dist[0] = 0;
		/*for(i=0;i<nodes;i++) {
			for(j=0;j<nodes;j++) {
				System.out.print(mat[i][j]+" ");
			}
			System.out.println();
		}*/
		System.out.println("-----");
		operate(0);
	}

	private void operate(int minimum) {
		int i=0;

		while(empty()!=1) {
			updateNeighbours(minimum);
			minimum = getMin();
			MSTsum+=node_dist[minimum];
			finalized.add(edge_list[minimum]);
			node_dist[minimum] = -infinity;
		}

		System.out.println("Minimum spanning tree is = ");

		for(i=1;i<finalized.size();i++) {
			System.out.println(finalized.get(i)/10+" - "+finalized.get(i)%10);
		}

		System.out.println("Sum is = "+MSTsum);
	}

	private int empty() {
		int i,j;
		for(i=0;i<nodes;i++) {
			if(node_dist[i]!=-infinity)
				return 0;
		}
		return 1;
	}

	private void updateNeighbours(int min) {
		int i;
		for(i=0;i<nodes;i++) {
			if(mat[min][i]!=-1) {
				if(mat[min][i]<node_dist[i]) {
					node_dist[i] = mat[min][i];
					if(min!=0)
						edge_list[i] = min*10+i;
					else
						edge_list[i] = i*10+min;
				}
			}
		}
	}

	private int getMin() {
		int minval = infinity;
		int minpos = 0;
		int i;

		for(i=0;i<nodes;i++) {
			if(node_dist[i]!=-infinity) {
				if(node_dist[i]<minval) {
					minval = node_dist[i];
					minpos = i;
				}
			}
		}
		return minpos;
	}

	public static void main(String[] args) {
		new Prims();
	}
}