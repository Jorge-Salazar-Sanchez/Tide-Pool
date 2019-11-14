/*Algorithm used to compute how much water would be captured in between
a set of blocks
*/

#include <iostream>
#include <string>


using namespace std;  
  
//Function that returns the water accumulated between blocks
int capturing_water(int array_blocks[], int n)  
{ 

    int captured_water = 0; //Variable used to store the accumulated water
	int i; //Variable used to iterate the left side of the array
	int j; //Variable used to iterate the right side of the array
	int current_block; //Variable pointing the current position of the array
	int smallest_block;//Variable used to choose the smallest block
	int hightest_left_block;//
	int hightest_right_block;
      
  //FOR loop used to iterate through all the elements of the array except the first one. 
  for (i = 1; i < n-1; ++i) { 

   //LEFT ITERATION       
    //1) Store the current position of the array.
    //2) Utilize the current position to find the highest 
    //block on the left side of the current position 
    current_block = array_blocks[i]; 
    hightest_left_block = current_block; 

    //3) Using a FOR loop, we can obtain the tallest block starting at
    //the first element of the array 
    for (j=0; j<i; j++) {
      if (hightest_left_block<array_blocks[j]) {
		  hightest_left_block = array_blocks[j];
		  }
    }

  //RIGHT ITERATION
    //1) Store the current position of the array.
    //2) Utilize the current position to find the highest 
    //block on the right side of the current position 
    current_block = array_blocks[i]; 
    hightest_right_block = current_block; 

    //3) Using a FOR loop, we can obtain the tallest block 
    for (int j=i+1; j<n; j++) { 
      if (hightest_right_block<array_blocks[j]) {
		  hightest_right_block = array_blocks[j];
      }
    }

    // Determining the smalllest block 
    smallest_block = min(hightest_right_block, hightest_left_block);
    
    // Accumulating water if the current block is the smallest one  
    captured_water = captured_water + (smallest_block-current_block);
   }  
  return captured_water; 
}

  
//Main function
int main()  
{  
//int arra_y[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//int arra_y[] = {2, 0, 2}; 
//int arra_y[] = {3, 0, 0, 2, 0, 4};
//int arra_y[] = {2, 1, 3, 0, 1, 2};

int size_user;

cout<<"Please, introduce the size of the array and press enter. Thank you." << endl;
cin >> size_user;

cout << endl;    
cout << "Please, press enter each time you introduce a value of the array. Thank you." <<endl;

int k;
int arra_y[size_user];
for ( k = 0 ; k < size_user ; k++ ) {
  cin >> arra_y[k];
}

//Here we calculate the size of the array in case it was not introduced by the user
//int size_array = sizeof(arra_y)/sizeof(arra_y[0]);  

cout <<endl;    
cout <<"The total of water accumulated is: "<<capturing_water(arra_y, size_user)<<" blocks";  
      
return 0;  
} 
