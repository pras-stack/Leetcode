class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(begin(boxTypes), end(boxTypes), [](auto& a, auto& b){ return a[1] > b[1];}); // sort by number of units / box
	int maxUnits = 0;
	for(auto& box : boxTypes) {
		if(truckSize <= 0) break;                    // keep choosing greedily till you run out of truckSize 
		maxUnits += min(truckSize, box[0]) * box[1]; // add (no of box * units) in that box
		truckSize -= box[0];
	}
	return maxUnits;
    }
};