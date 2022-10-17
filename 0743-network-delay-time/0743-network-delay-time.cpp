class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &edges, int n, int k)
        {
           	// To store the adjacency list of the given graph.
            vector<vector<pair<int, int>>> adj(n + 1);

           	// Create the adjacency list.
            for (vector<int> &u: edges)
            {
                adj[u[0]].push_back({ u[1],
                    u[2] });
            }

           	// To store the shortest path length for each node from the source node 'K'.
            vector<int> dist(n + 1, INT_MAX);

            dist[k] = 0;

           	// Min priority queue which stores the pair of path distance and the node itself.
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({ 0,
                k });

            while (!pq.empty())
            {
               	// Extract the top element and pop it from the priority_queue.
                pair<int, int> u = pq.top();
                pq.pop();
                int w = u.first;
                int v = u.second;

                if (dist[v] < w)
                {
                    continue;
                }

                for (pair<int, int> edge: adj[v])
                {
                   	// Perform the weight relaxation.
                    if (dist[edge.first] > dist[v] + edge.second)
                    {
                        dist[edge.first] = dist[v] + edge.second;
                        pq.push({ dist[edge.first],
                            edge.first });
                    }
                }
            }

           	// Get the maximum value.
            int mn = 0;
            for (int i = 1; i <= n; i++)
            {
                mn = max(mn, dist[i]);
            }

            if (mn == INT_MAX)
            {
                return -1;
            }
            else
            {
                return mn;
            }
        }
        };