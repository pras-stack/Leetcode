class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& input)
    {
        // Set 'N' equal number of vertices.
    int n = input.size();

    // Initialize a boolean vector 'SAFE' of size 'N' with value false.
    vector<int> safe(n, false);

    // Create a queue 'Q' to store the safe states.
    queue<int> q;

    // Create a vector of sets 'R_GRAPH' and 'graph' of size 'N'.
    vector<unordered_set<int>> graph(n), rGraph(n);

    for (int startVertex = 0; startVertex < n; startVertex++)
    {
        // If a vertex has no parent, push it into the queue.
        if (input[startVertex].size() == 0)
            q.push(startVertex);

        // Filling 'GRAPH' and 'R_GRAPH'.
        for (int endVertex: input[startVertex])
        {
            graph[startVertex].insert(endVertex);
            rGraph[endVertex].insert(startVertex);
        }
    }

    // Doing BFS on all the safe states.
    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();

        // Vertex is present in the queue means it's safe.
        safe[currentVertex] = true;

        // Remove its edges with parents using rgraph.
        for (int parent : rGraph[currentVertex])
        {
            graph[parent].erase(currentVertex);

            // If any of the parent has no outgoing edges in 'GRAPH' means it is a safe node.
            if (graph[parent].size() == 0)
                q.push(parent);
        }
    }

    // 'ANSWER' vector to save vertex numbers of all the vertices.
    vector<int> answer;

    // Iterating through the 'SAFE' vector to check which of the vertices are marked safe.
    for (int i = 0; i < n; i++)
    {
        if (safe[i])
            answer.push_back(i);
    }
    return answer;
    }
};