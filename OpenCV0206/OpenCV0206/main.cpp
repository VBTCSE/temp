// OpenCV0206

// The purpose of this program is to filter an image and show the result.

// This program uses the GaussianBlur smoothing filter.
// Both the initial image and the processed result are shown.

// Correct usage: OpenCV0206.exe input_image_filename filtered_image_filename maximum_number_smoothing_cycles
// Example: OpenCV0205.exe Desert.jpg Desert_smoothed.jpg 20

// Program control:
// Quit: press <Esc> key while cursor is in the image window.



// Refer to http://docs.opencv.org/master for relevant documentation.


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;







//-------------------------------------------------------------------------
// Define global variables
// Denote that these are global with "g_"...
// These will be accessible to both the main function and to the 
// trackbar slider callback function.
//-------------------------------------------------------------------------







int g_slider_position = 1;	// Equals number of filtering cycles currently being used.
Mat g_imageInput;			// Declare a Mat object to contain the inputput filtered image.
Mat g_imageOutput;			// Declare a second Mat object to contain the output filtered image.







void onTrackbarSlide(int pos, void*)
{
	//-------------------------------------------------------------------------
	// This is a callback function which is run in response to the slider moving.
	//-------------------------------------------------------------------------



	//-------------------------------------------------------------------------
	// Use the set method of the global VideoCapture object, to set the 0-based 
	// index, of the frame to be shown next, as specified by the position of 
	// the trackbar.
	//-------------------------------------------------------------------------

#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code

	if (pos > 0)
	{
		GaussianBlur(g_imageInput, g_imageOutput, Size(5, 5), 3, 3);

		for (int i = 1; i < pos; i++)
		{
			GaussianBlur(g_imageOutput, g_imageOutput, Size(5, 5), 3, 3);
		}
	}
	else
	{
		g_imageInput.copyTo(g_imageOutput);
	}

}







int main(int argc, char** argv)
{
	//-------------------------------------------------------------------------
	// Test whether the number of arguments (argc) is not equal to 4.
	// If it is not equal to 3, output a message showing what the correct
	// usage of this program is, then pause for the user response and return -1.
	//-------------------------------------------------------------------------

	if (argc != 4)
	{
		cout << " Usage: " << argv[0] << " input_image_filename filtered_image_filename maximum_number_smoothing_cycles" << endl;
		system("pause");
		return -1;
	}







	//-------------------------------------------------------------------------
	// Declare char* (c-strings) to hold the two image filenames and the
	// number of smoothing cycles.
	//-------------------------------------------------------------------------

	char* imageNameInput = argv[1];		// input file
	char* imageNameOutput = argv[2];	// output file
	char* smax_number_cycles = argv[3];		// number of smoothing cycles







	//-------------------------------------------------------------------------
	// Convert the c-string number of smoothing cycles to an integer and verify
	// that it is >= 1.
	//-------------------------------------------------------------------------

	int maxNumCycles = atoi(smax_number_cycles);
	if (maxNumCycles < 1)
	{
		cout << "Maximum number_smoothing_cycles must be >= 1." << endl;
		system("pause");
		return -1;
	}







	//-------------------------------------------------------------------------
	// Output the instructions for contolling the video playback.
	// Program control:
	// Quit:  press <Esc> key while cursor is in the image window.
	//-------------------------------------------------------------------------

	cout << "Program control:\n";
	cout << "Quit:  press <Esc> key while cursor is in the image window.\n\n";







	//-------------------------------------------------------------------------
	// Use the imread function to read in a color image from a file 
	// whose name is in imageNameInput.  Store the image in the Mat object allocated
	// above.
	//-------------------------------------------------------------------------

	g_imageInput = imread(imageNameInput, IMREAD_COLOR);







	//-------------------------------------------------------------------------
	// Use the data attribute of the Mat class to test whether any data was
	// actually input.  If no data was input (file not found or could not be
	// read as an image), then output a message, wait for the user's response
	// and return -1.
	//-------------------------------------------------------------------------

	if (!g_imageInput.data)
	{
		cout << "Could not open or find the input image" << endl;
		system("pause");
		return -1;
	}







	//-------------------------------------------------------------------------
	// Use the namedWindow function to create a window for displaying the input
	// image.
	//-------------------------------------------------------------------------

	namedWindow("Input Image", WINDOW_AUTOSIZE);







	//-------------------------------------------------------------------------
	// Use the namedWindow function to create a window for displaying the
	// filtered image.
	//-------------------------------------------------------------------------

	namedWindow("Filtered Image", WINDOW_AUTOSIZE);







	//-------------------------------------------------------------------------
	// Use the createTrackbar function to create a trackbar and attach it to
	// the filtered image window created above.  Use the global cycle number currently being
	// used to position the slider.  Use the input maximum cycle number to set the maximal position of the slider.
	// Pass the name of the callback function (onTrackbarSlide) as the pointer
	// to the function to be called every time that the slider changes position.
	// Use the default value of userdata for the last parameter (see the OpenCV
	// function documentation).
	//-------------------------------------------------------------------------

#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	createTrackbar("Filtering Cycles", "Filtered Image", &g_slider_position, maxNumCycles, onTrackbarSlide);







	//-------------------------------------------------------------------------
	// Use the imshow function to display the color image in the window that was 
	// created above.
	//-------------------------------------------------------------------------

	imshow("Input Image", g_imageInput);







	//-------------------------------------------------------------------------
	// Use the GaussianBlur function to filter the input image as many times 
	// as given by the value of g_slider_position.
	//-------------------------------------------------------------------------

	if (g_slider_position > 0)
	{
		GaussianBlur(g_imageInput, g_imageOutput, Size(5, 5), 3, 3);

		for (int i = 1; i < g_slider_position; i++)
		{
			GaussianBlur(g_imageOutput, g_imageOutput, Size(5, 5), 3, 3);
		}
	}
	else
	{
		g_imageInput.copyTo(g_imageOutput);
	}





	//-------------------------------------------------------------------------
	// Use a "forever" loop to repeatedly cycle, allowing the user to move the 
	// slider.
	//-------------------------------------------------------------------------

	for (;;)
	{





		//-------------------------------------------------------------------------
		// Use the setTrackbarPos function to set the position of the trackbar which
		// is attached to the window created above.  
		// Pass the slider position, obtained above as the new position.
		//-------------------------------------------------------------------------

#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		setTrackbarPos("Filtering Cycles", "Filtered Image", g_slider_position);





		//-------------------------------------------------------------------------
		// Use the imshow function to display the filtered image in the window 
		// that was created above.
		//-------------------------------------------------------------------------

		imshow("Filtered image", g_imageOutput);




		//-------------------------------------------------------------------------
		// Use the waitKey function to wait 33 milliseconds, or until the user 
		// presses an <Esc> key, in the image window.  Use the return value of waitKey
		// to determine whether an <Esc> was pressed by the user.  If an <Esc> was pressed,
		// break out of the "forever" loop, ending the program.
		//-------------------------------------------------------------------------

		char c = waitKey(33);

		if (c == 27)
		{
			// quit
			break;
		}

	}





	//-------------------------------------------------------------------------
	// Use the imwrite function to write the filtered image into the output
	// image file.
	//-------------------------------------------------------------------------

	imwrite(imageNameOutput, g_imageOutput);






	return 0;

}