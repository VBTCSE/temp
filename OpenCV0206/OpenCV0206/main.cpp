// OpenCV0206

// The purpose of this program is to filter an image and show the result.



// This program uses the GaussianBlur smoothing filter.
// Both the initial image and the processed result are shown.
// The processed result is written to a file before the program ends.



// Correct usage: OpenCV0206.exe input_image_filename output_image_filename maximum_number_smoothing_cycles
// Example: OpenCV0205.exe Desert.jpg Desert_smoothed.jpg 20



// Program control:
// Move slider: change number of filtering cycles.
// Quit:        press <Esc> key while cursor is in the image window.



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







int g_numFilterCycles = 1;	// Equals number of filtering cycles currently being used.
Mat g_imageInput;			// Declare a Mat object to contain the inputput filtered image.
Mat g_imageOutput;			// Declare a second Mat object to contain the output filtered image.







void onTrackbarSlide(int pos, void*)
{
	//-------------------------------------------------------------------------
	// This is a callback function which is run in response to the slider moving.
	//-------------------------------------------------------------------------

	// The value of the slider position (pos) is the number of filtering cycles.




	if (pos > 0)	// If the number of filtering cycles is > 0: do filtering
	{
		// Do the first filter cycle, 
		// source image is g_imageInput
		// destination image is g_imageOutput

		// Use Gaussian filtering 
		// with a standard deviation of 3 in both the x and y directions.
		// Use a 5 X 5 filter kernel.

		//-------------------------------------------------------------------------
		// Use the GaussianBlur function to filter the source image into the 
		// destination image.  Use a 5 X 5 kernel, and std dev of 3, both directions.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		GaussianBlur(g_imageInput, g_imageOutput, Size(5, 5), 3, 3);

		for (int i = 1; i < pos; i++)	// Loop over all additional filtering cycles 
										// (Note: loop does not execute if pos <= 1)
		{
			// Do the first filter cycle, 
			// source image is g_imageOutput
			// destination image is g_imageOutput
			// i.e. source and destination are the same for all cycles after the first.

			//-------------------------------------------------------------------------
			// Use the GaussianBlur function to filter the source image into the 
			// destination image.  Note that these are the same entity, here.
			// Use a 5 X 5 kernel, and std dev of 3, both directions.
			//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
			GaussianBlur(g_imageOutput, g_imageOutput, Size(5, 5), 3, 3);
		}
	}
	else	// Otherwise, if the number of filtering cycles is zero, 
			// just copy source image to destination image (no filtering).
	{
		// source image is g_imageInput
		// destination image is g_imageOutput

		//-------------------------------------------------------------------------
		// Use the copyTo method of the Mat class to copy the image from the source
		// image to the destination image.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		g_imageInput.copyTo(g_imageOutput);
	}

}







int main(int argc, char** argv)
{
	//-------------------------------------------------------------------------
	// Test whether the number of arguments (argc) is not equal to 4.
	// If it is not equal to 4, 
	// output a message showing what the correct usage of this program is, 
	// then pause for the user response 
	// and return -1.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
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

	char* imageNameInput = argv[1];			// input file name
	char* imageNameOutput = argv[2];		// output file name
	char* smax_number_cycles = argv[3];		// maximum number of smoothing cycles







	//-------------------------------------------------------------------------
	// Convert the c-string number of smoothing cycles to an integer and verify
	// that it is >= 1.
	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Use the atoi function of C++ to convert from a string (smax_number_cycles)
	// to an integer.
	// Then, check whether the integer is < 1.  If it is, 
	// Output an error message,
	// then pause
	// and return -1.
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
	// Move slider: change number of filtering cycles.
	// Quit:        press <Esc> key while cursor is in the image window.
	//-------------------------------------------------------------------------

	cout << "Program control:\n";
	cout << "Move slider: change number of filtering cycles.\n";
	cout << "Quit:        press <Esc> key while cursor is in the image window.\n\n";







	//-------------------------------------------------------------------------
	// Use the imread function to read in a color image from a file 
	// whose name is in imageNameInput.  Store the image in the global Mat object 
	// allocated above.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	g_imageInput = imread(imageNameInput, IMREAD_COLOR);







	//-------------------------------------------------------------------------
	// Use the data attribute of the Mat class to test whether any data was
	// actually input.  
	// If no data was input (file not found or could not be read as an image), 
	// then output a message, 
	// pause for the user's response
	// and return -1.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
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
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	namedWindow("Input Image", WINDOW_AUTOSIZE);







	//-------------------------------------------------------------------------
	// Use the namedWindow function to create a window for displaying the
	// output filtered image.  
	// Note: this must have a different name from the input image window, above.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	namedWindow("Filtered Image", WINDOW_AUTOSIZE);







	//-------------------------------------------------------------------------
	// Use the createTrackbar OpenCV function to create a trackbar 
	// and attach it to the filtered image window created above. 
	//
	// Use the global cycle number (g_numFilterCycles) currently being used,
	// to position the slider.
	//
	// Use the input maximum cycle number (maxNumCycles),
	// to set the maximal position of the slider.
	//
	// Pass the name of the callback function (onTrackbarSlide) as the pointer
	// to the function to be called every time that the slider changes position.
	//
	// Use the default value of userdata (no input parameter required),
	// for the last parameter (see the OpenCV function documentation).
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	createTrackbar("# Cycles", "Filtered Image", &g_numFilterCycles, maxNumCycles, onTrackbarSlide);







	//-------------------------------------------------------------------------
	// Use the imshow function to display the color image in the first window 
	// that was created above.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	imshow("Input Image", g_imageInput);







	//-------------------------------------------------------------------------
	// Use the GaussianBlur function to filter the input image as many times 
	// as given by the value of g_numFilterCycles.
	//
	// Use the same type of code as in onTrackbarSlide, above.
	// Note: the number of cycles is g_numFilterCycles here, 
	// whereas it was pos in onTrackbarSlide.
	//-------------------------------------------------------------------------
	if (g_numFilterCycles > 0)
	{
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		GaussianBlur(g_imageInput, g_imageOutput, Size(5, 5), 3, 3);

		for (int i = 1; i < g_numFilterCycles; i++)
		{
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
			GaussianBlur(g_imageOutput, g_imageOutput, Size(5, 5), 3, 3);
		}
	}
	else
	{
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
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
		// is attached to the output window created above.  
		// Pass the number of filtering cycles, obtained above as the new slider position.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		setTrackbarPos("Filtering Cycles", "Filtered Image", g_numFilterCycles);





		//-------------------------------------------------------------------------
		// Use the imshow function to display the filtered image in the output window 
		// that was created above.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		imshow("Filtered image", g_imageOutput);




		//-------------------------------------------------------------------------
		// Use the waitKey function to wait 33 milliseconds, or until the user 
		// presses an <Esc> key, in the image window.  
		// Use the return value of waitKey to determine whether an <Esc> was pressed by the user.  
		// If an <Esc> was pressed, break out of the "forever" loop.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		char c = waitKey(33);
		if (c == 27)
		{
			break;
		}

	}





	//-------------------------------------------------------------------------
	// Use the imwrite function to write the filtered image into the output
	// image file.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	imwrite(imageNameOutput, g_imageOutput);






	return 0;

}