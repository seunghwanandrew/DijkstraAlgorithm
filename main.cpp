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

	/* �ִ� �Ÿ� �迭 �ʱ�ȭ 
		 - �־����� aNode �� �� + 1��ŭ �迭�� Ȯ���ϰ�, MAX ������ �ʱ�ȭ �Ѵ�. 	*/

	shortestPath.resize(aNode + 1);

	for (int i = 1; i < shortestPath.size(); i++)
	{
		shortestPath[i] = INT_MAX;
		cout << "shortestPath[" << i << "] is initialized as " << shortestPath[i] << endl;
	}
	// fill(shortestPath.begin(), shortestPath.end(), INT_MAX);
	cout << "-------------------------------------------------------------------------" << endl;

	/* ��� �湮 ���θ� �Ǵ��ϴ� �迭 �ʱ�ȭ
		 - false ������ �ʱ� ȭ */

	visitedNode.resize(aNode + 1);
	
	for (bool elem : visitedNode)
	{
		elem = false;
	}
	
	// fill(visitedNode.begin(), visitedNode.end(), false);


	/* ���� ����Ʈ �ʱ�ȭ �ϱ� */
	adjacencyList.resize(aNode + 1);

	
	for (int i = 0; i < aEdge; i++)
	{
		int nodeNum, nextVertex, weightToNextVertex;
		cin >> nodeNum >> nextVertex >> weightToNextVertex;
		
		adjacencyList[nodeNum].push_back(make_pair(nextVertex, weightToNextVertex)); // { {[2,2],[3,3]}, {[3,4], [4,5]}, {[4,6]}, { } ,{[1,1]}};

		cout << "adjacencyList[" << nodeNum << "] = [" << nextVertex << ", " << weightToNextVertex << "]" << endl;
	}
	cout << "-------------------------------------------------------------------------" << endl;

	/* queue �� ��Ҹ� �ְ� loop ���� 
		- queue ��� (���� ����� �ִܰŸ� ��, ���۳��) */

	shortestPath[startNode] = 0; // �ּ� ���� ����� 1�� �̵� �ּ� ���� 0 �̴�. (������ �̹Ƿ�)
	q.push(make_pair(shortestPath[startNode], startNode));

	/* Loop ���� �� ���� */
	while (!q.empty())
	{
		// ���� ���κ��� �����ϸ鼭 �湮 ǥ�ø� �����Ѵ�. ���� �湮 ǥ�ð� true�� ����� �������� �̵��Ѵ�.
		edge current = q.top(); 
		q.pop();
		if (q.empty()) cout << "q is empty" << endl;

		int currentVertex = current.second;
		cout << "Current Vertex is " << currentVertex << endl;

		if (visitedNode[currentVertex]) continue;
		visitedNode[currentVertex] = true;
		if (visitedNode[currentVertex] == true) cout << "Current Vertex " << currentVertex << " is visited" << endl;
		cout << "-------------------------------------------------------------------------" << endl;

		// ���� ����Ʈ�� ��ϵ� (���� �̵� vertex, �̵��ϱ� ���� ��) �� ȣ���Ͽ�, ���� ��ϵ� next Vertex�� �̵��ϴ� ���� ���Ͽ� �� ���� ���� ���!
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

	// ���!
	for (int i = 1; i < shortestPath.size(); i++)
	{
		if (visitedNode[i]) cout << shortestPath[i] << endl;
		else cout << "INF" << endl;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	return 0;
}