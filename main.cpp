#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> adjacencyList;
vector<int> shortestPath;
vector<bool> visitedNode;
priority_queue<edge> q;

int aNode, aEdge, startNode;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> aNode >> aEdge >> startNode;

	/* 최단 거리 배열 초기화 
		 - 주어지는 aNode 의 수 + 1만큼 배열을 확장하고, MAX 값으로 초기화 한다. 	*/

	shortestPath.resize(aNode + 1);

	for (int i = 1; i < shortestPath.size(); i++)
	{
		shortestPath[i] = INT_MAX;
		cout << "shortestPath[" << i << "] is initialized as " << shortestPath[i] << endl;
	}
	// fill(shortestPath.begin(), shortestPath.end(), INT_MAX);
	cout << "-------------------------------------------------------------------------" << endl;

	/* 노드 방문 여부를 판단하는 배열 초기화
		 - false 값으로 초기 화 */

	visitedNode.resize(aNode + 1);
	
	for (bool elem : visitedNode)
	{
		elem = false;
	}
	
	// fill(visitedNode.begin(), visitedNode.end(), false);


	/* 인접 리스트 초기화 하기 */
	adjacencyList.resize(aNode + 1);

	
	for (int i = 0; i < aEdge; i++)
	{
		int nodeNum, nextVertex, weightToNextVertex;
		cin >> nodeNum >> nextVertex >> weightToNextVertex;
		
		adjacencyList[nodeNum].push_back(make_pair(nextVertex, weightToNextVertex)); // { {[2,2],[3,3]}, {[3,4], [4,5]}, {[4,6]}, { } ,{[1,1]}};

		cout << "adjacencyList[" << nodeNum << "] = [" << nextVertex << ", " << weightToNextVertex << "]" << endl;
	}
	cout << "-------------------------------------------------------------------------" << endl;

	/* queue 에 요소를 넣고 loop 시작 
		- queue 요소 (시작 노드의 최단거리 값, 시작노드) */

	shortestPath[startNode] = 0; // 최소 시작 노드인 1의 이동 최소 값은 0 이다. (시작점 이므로)
	q.push(make_pair(shortestPath[startNode], startNode));

	/* Loop 조건 및 내용 */
	while (!q.empty())
	{
		// 시작 노드로부터 시작하면서 방문 표시를 진행한다. 만약 방문 표시가 true인 경우라면 다음으로 이동한다.
		edge current = q.top(); 
		q.pop();
		if (q.empty()) cout << "q is empty" << endl;

		int currentVertex = current.second;
		cout << "Current Vertex is " << currentVertex << endl;

		if (visitedNode[currentVertex]) continue;
		visitedNode[currentVertex] = true;
		if (visitedNode[currentVertex] == true) cout << "Current Vertex " << currentVertex << " is visited" << endl;
		cout << "-------------------------------------------------------------------------" << endl;

		// 인접 리스트에 기록된 (다음 이동 vertex, 이동하기 위한 값) 을 호출하여, 현재 기록된 next Vertex로 이동하는 값과 비교하여 더 작은 값을 기록!
		for (int i = 0; i < adjacencyList[currentVertex].size(); i++)
		{
			int nextVertex = adjacencyList[currentVertex][i].first;
			int toNextVertexValue = adjacencyList[currentVertex][i].second;
			cout << "Next Vertex is " << nextVertex << " and Weight to Next vertext is " << toNextVertexValue << endl;

			if (shortestPath[nextVertex] > shortestPath[currentVertex] + toNextVertexValue)
			{
				shortestPath[nextVertex] = shortestPath[currentVertex] + toNextVertexValue;
				q.push(make_pair(shortestPath[nextVertex], nextVertex));
			}
			cout << "shortestPath[" << nextVertex << "] is " << shortestPath[nextVertex] << " and shortestPath[" << currentVertex << "] + toNextVertexValue: "
				<< toNextVertexValue << endl;
			cout << "-------------------------------------------------------------------------" << endl;
		}

	}

	// 출력!
	for (int i = 1; i < shortestPath.size(); i++)
	{
		if (visitedNode[i]) cout << shortestPath[i] << endl;
		else cout << "INF" << endl;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	return 0;
}