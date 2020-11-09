#include "heap.h"



/* 	Weizheng Jiang
	z1861817
	csci340 section2
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/




//takes the input from a file and stores it in a vector
template <typename T>
void get_list(vector<T> &v, const char *path) {
	//v: a vector container for T data type,
	//path: const char pointer to the path of the file to read from
	v.clear();
	T data;
	ifstream inFile;
	inFile.open(path);
	//if the file cannot open, print out the error message and exit
	if(inFile.fail())
		{
		cout << "FAILURE TO OPEN" << path;
		exit(1);
		}
	//input the data from the input file
	inFile >> data;
	while(inFile)
		{
			//use the push_back method to store the data in the vector
		v.push_back(data);
		inFile >> data;
		}
	//close the input file
	inFile.close();
}

//makes and sorts a heap
template <typename T, typename P>
void construct_heap(vector<T> &v, P pred) {

	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

int main() {
  vector<int>    v1;  // heap of integers
  vector<float>  v2;  // heap of floating-pt nums
  vector<string> v3;  // heap of strings

  // print header message
  cout << "\t\t\t*** Heaps and Heapsort - Output ***\n\n";

  // first heap

  cout << "first heap - ascending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, less<int>());
  print_list<int> print1(v1.size(), INT_SZ, INT_LN);
  for_each(v1.begin(), v1.end(), print1);

  cout << "first heap - descending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, greater<int>());
  for_each(v1.begin(), v1.end(), print1);

  // second heap

  cout << "second heap - ascending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, less<float>());
  print_list<float> print2(v2.size(), FLT_SZ, FLT_LN);
  for_each(v2.begin(), v2.end(), print2);

  cout << "second heap - descending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, greater<float>());
  for_each(v2.begin(), v2.end(), print2);

  // third heap

  cout << "third heap - ascending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, less<string>());
  print_list<string> print3(v3.size(), STR_SZ, STR_LN);
  for_each(v3.begin(), v3.end(), print3);

  cout << "third heap - descending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, greater<string>());
  for_each(v3.begin(), v3.end(), print3);

  // print termination message
  cout << "\t\t\t*** end of program execution ***\n\n";
  return 0;
}
