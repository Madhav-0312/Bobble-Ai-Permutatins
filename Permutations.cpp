#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void print(vector<vector<string> > &arr) 
{ 
    // number of arrays 
    int n = arr.size(); 
  
    // to keep track of next element in each of 
    // the n arrays 
    int* indices = new int[n]; 
  
    // initialize with first element's index 
    for (int i = 0; i < n; i++) 
        indices[i] = 0; 
  
    while (1) { 
  
        // print current combination 
        for (int i = 0; i < n; i++) 
            cout << arr[i][indices[i]];
        cout << endl; 
  
        // find the rightmost array that has more 
        // elements left after the current element  
        // in that array 
        int next = n - 1; 
        while (next >= 0 &&  
              (indices[next] + 1 >= arr[next].size())) 
            next--; 
  
        // no such array is found so no more  
        // combinations left 
        if (next < 0) 
            return; 
  
        // if found move to next element in that  
        // array 
        indices[next]++; 
  
        // for all arrays to the right of this  
        // array current index again points to  
        // first element 
        for (int i = next + 1; i < n; i++) 
            indices[i] = 0; 
    } 
} 


 int main() {
	ifstream ip("input.csv");
	vector <vector<string> > arr;
	while(ip.peek()!=EOF) {
		string a;
		vector<string> row;
		while(getline(ip,a,',')) 	
			row.push_back(a);
		arr.push_back(row);
		
		
}
ip.close();
print(arr);

return 0;
}
	
