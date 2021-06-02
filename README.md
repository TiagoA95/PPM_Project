# PPM_Project
Various ways to edit .ppm images


Available functions so far:


_______________________________________________________

-Flip image horizontally

./ppm_h_flip [input.ppm [output.ppm]]


_______________________________________________________


-Flip image vertically

./ppm_v_flip [input.ppm [output.ppm]]


_______________________________________________________


-Flip image diagonally

./ppm_d_flip [input.ppm [output.ppm]]


_______________________________________________________


-Add RBG color to image

./ppm_addRGB dR dG dB [input.ppm [output.ppm]]


_______________________________________________________


-Convert to grayscale

./ppm_grayscale [input.ppm [output.ppm]]


_______________________________________________________


-Convert to black and white

./ppm_bw threshold [input.ppm [output.ppm]]


_______________________________________________________


-Rotate image 90º clockwise

./ppm_rot_right [input.ppm [output.ppm]]


_______________________________________________________


-Rotate image 90º counterclockwise

./ppm_rot_left [input.ppm [output.ppm]]


_______________________________________________________

 
-Add a border to the image

./ppm_addBorder npixels R G B [input.ppm [output.ppm]]


_______________________________________________________


-Concatenate 2 images

./ppm_concat image1.ppm image2.ppm [output.ppm]


_______________________________________________________


-Crop image

./ppm_crop x0 y0 x1 y1 [input.ppm [output.ppm]]


_______________________________________________________


-Overlay an image on top of another

./ppm_overlay x y overlay.ppm [input.ppm [output.ppm]]


_______________________________________________________


-Make the maxcolor "pop"

./ppm_maxcolor [input.ppm [output.ppm]]


_______________________________________________________


-Add horizontal bars across the image

./ppm_hbar width R G B [input.ppm [output.ppm]]


_______________________________________________________


-Add vertical bars across the image

./ppm_vbar width R G B [input.ppm [output.ppm]]
