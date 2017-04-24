// OpenCV0206

// The purpose of this program is to filter an image and show the result.

// This program uses the GaussianBlur smoothing filter.
// Both the initial image and the processed result are shown.

// Correct usage: OpenCV0206.exe input_image_filename filtered_image_filename

// Program control:
// Quit:		press any key while cursor is in the image window.



// Refer to http://docs.opencv.org/master for relevant documentation.


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;





int main(int argc, char** argv)
{
	//-------------------------------------------------------------------------
	// Test whether the number of arguments (argc) is not equal to 3.
	// If it is not equal to 3, output a message showing what the correct
	// usage of this program is, then pause for the user response and return -1.
	//-------------------------------------------------------------------------

	if (argc != 2)
	{
		cout << " Usage: " << argv[0] << " input_image_filename filtered_image_filename" << endl;
		system("pause");
		return -1;
	}







	//-------------------------------------------------------------------------
	// Output the instructions for contolling the video playback.
	// Program control:
	// Quit:  press any key while cursor is in the image window.
	//-------------------------------------------------------------------------

	cout << "Program control:\n";
	cout << "Quit:  press any key while cursor is in the image window.\n\n";







	//-------------------------------------------------------------------------
	// Use the open function of the global VideoCapture object to open the video
	// from a file whose name is in argv[1]
	//-------------------------------------------------------------------------

#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code




	return 0;

}