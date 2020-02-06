#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
//Print function to print permutations
void print( vector < vector < string > >  &arr) 
{ 
    // number of array of strings 
    int n = arr.size(); 
  
    // To keep track of next element in each of the arrays 
   
    int* track = new int[n]; 
  
    // Initialize with 0
    for (int i = 0; i < n; i++) 
        track[i] = 0; 
  
    while (1) { 
  
        // Print current Permutation 
        for (int i = 0; i < n; i++) 
            cout << arr[i][track[i]];
        cout << endl; 
  
        // Find the rightmost array that has more elements left after the current element in that array 
       
        int next = n - 1; 
        while (next >= 0 &&  
              (track[next] + 1 >= arr[next].size())) 
            next--; 
  
        // Exit when no more Permutations left
	    
        if (next < 0) 
            return; 
  
        // If found move to next element in that array
        
        track[next]++; 
  
        // For all arrays to the right of this array current index again points to first element  
      
	    
        for (int i = next + 1; i < n; i++) 
            track[i] = 0; 
    } 
} 

// Main function to read file

 int main(int argc, const char *argv[]) {
	 // Open file
	ifstream ip( " argv[0] " );
	 
	 // Create a vector of vectors of type string
	 
	vector < vector <string> > arr;
	 
	 // Iterate till the end of file
	 
	while( ip.peek() != EOF) {
		string a;
		
		// Take out rows from file
		vector< string > row;
		
		// Insert rows into the 2-D vector
		while( getline ( ip , a , ',' ) ) 	
			row.push_back(a);
		arr.push_back(row);
		
		
}
	 // Close the file
ip.close();
	 // Function call
print(arr);

return 0;
}
	
