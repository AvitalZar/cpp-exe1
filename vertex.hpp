#include <iostream>
namespace graph{
	class Vertex
	{
	private:
		EdgeTo *neighbors;
		int numOfNeighbors;
	public:
		Vertex();
		void add_neighbor(int num);
		void add_neighbor(int num, int weight);
		void del_neighbor(int num);
		void set_weight(int ver, int weight);
		std::string toString();
		~Vertex();
	};

	typedef struct EdgeTo{
		int vertex = -1;
		int weight = 0;
	};
}