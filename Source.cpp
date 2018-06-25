/************************
* YAHYA CEYLANI
* 25/06/2018
* That program reads 3 points with x and y coordinates (2d) and a 4. point to check that the 4. point whether
* inside or outside of the area of triangle that three points create
*************************/


#include <iostream>
#include <fstream>

int main(){
	int xArray[3], yArray[3], x, y;

	std::cout << "Please enter the x and y values with one space not a comma between them!" << std::endl;

	// get 3 points like (x,y)
	std::cout << "x1, y1: ";
	std::cin >> xArray[0] >> yArray[0];
	std::cout << "x2, y2: ";
	std::cin >> xArray[1] >> yArray[1];
	std::cout<< "x3, y3: ";
	std::cin >> xArray[2] >> yArray[2];
	// read the point that will be checked whether in triangle or not
	std::cout << "x4, y4: ";
	std::cin >> x >> y;
	

	// check that 3 points whether creates a triangle or not
	// fabs() function is not used for absolute values
	// an AND operator used instead of fabs()

	int a, b, c; // length of edges of triangle
	a = (xArray[0] - xArray[1]) * (xArray[0] - xArray[1]) + (yArray[0] - yArray[1]) * (yArray[0] - yArray[1]);	// between 0 and 1
	b = (xArray[0] - xArray[2]) * (xArray[0] - xArray[2]) + (yArray[0] - yArray[2]) * (yArray[0] - yArray[2]);	// between 0 and 2 
	c = (xArray[2] - xArray[1]) * (xArray[2] - xArray[1]) + (yArray[2] - yArray[1]) * (yArray[2] - yArray[1]);	// betweeb 1 and 2
	
	if (b < (a + c) && c < (a + b) && a < (b + c)){ // check for a
		std::cout << "These three points do not create a triangle!!!" << std::endl;
		return 0;
	} // end if

	if (a < (b + c) && c < (b + a) && b < (a + c)){ // check for b
		std::cout << "These three points do not create a triangle!!!" << std::endl;
		return 0;
	} // end if

	if (a < (b + c) && b < (a + c) && c < (a + b)){ // check for c
		std::cout << "These three points do not create a triangle!!!" << std::endl;
		return 0;
	} // end if




	// To decide the fourth point location whether in area of triangle or not
	// First sort xArray and yArray with insertion sort (small number of elements will not effect runtime)
	// Then check the fourth point's x and y coordinates are between the xArray[0] and xArray[2] for x and
	// yArray[0] and yArray[2] for y

	for (unsigned int i = 0; i < 3; i++){
		for (unsigned int j = i + 1; j < 3; j++){
			if (xArray[i] > xArray[j]){ // check for x values
				// swap the elements
				int temp = xArray[i];
				xArray[i] = xArray[j];
				xArray[j] = temp;
			} // end if

			if (yArray[i] > yArray[j]){ // check for y values
				// swap the elements
				int temp = yArray[i];
				yArray[i] = yArray[j];
				yArray[j] = temp;
			} // end if

		} // end nested for
	} // end for


	// check the x and y values of fourth point
	if (x < xArray[2] || x > xArray[0] || y < yArray[2] || y > yArray[0]){
		std::cout << std::endl << "4. point is inside of the area of triangle." << std::endl;
	}else{
		std::cout << std::endl << "4. point is outside of the area of triangle" << std::endl;
	} // end else ,if


	return 0;
}









