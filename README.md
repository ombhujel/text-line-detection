Given the image, if there is enough gap between the vertical column, it will be bounded by a box.

Below is the input Image
45 50 0 1
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . 1 1 1 1 . . . . . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. 1 1 1 1 1 . . . . . . . . . . . 1 . 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . 
. 1 1 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 1 1 . . . 1 1 1 1 1 . . . . . . . . . 
. . 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 1 1 . . . . . 1 1 . 1 . . . 1 1 1 1 1 . . . . . . . . . 
. 1 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 . . . . . . 1 1 1 1 1 . . . 1 . 1 1 1 . . . 1 1 1 1 . . 
. . . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . 1 1 1 1 . . . . . 1 1 1 1 . . . 1 1 1 1 1 . 
. . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . 1 1 1 1 . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 1 . 
. . 1 1 1 1 . . . . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 . 
. 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . . 
. 1 1 1 1 1 . 1 . . 1 1 1 1 1 . . . . 1 1 1 1 . . . . 1 1 1 1 . 1 . . . 1 1 1 1 1 . . . . . . . . . 
. 1 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 . . . 1 1 1 1 1 . . . . . . . . . 
. . 1 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 . . . . 1 1 1 1 . . 
. . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 1 . 
. . . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . 1 1 1 1 . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 1 . 
. 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . . . . . . . . . 1 1 1 1 1 . 
. 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . 
. . 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 . . . . . . 1 1 1 1 1 . . . 1 . 1 1 1 . . . . . . . . . 
. . 1 1 1 1 . . . . 1 . 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 . . . 1 1 1 1 1 . . . . . . . . . 
. 1 1 1 1 . . . . . 1 1 1 1 1 . . . . . 1 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 . . . . 1 1 1 . 1 . 
. . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . . 1 1 1 1 . . . . 1 . 1 1 1 . . . 1 1 1 1 1 . 
. . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . 1 1 1 1 . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 . 
. 1 1 1 1 1 . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 . . 
. 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . 1 1 . 1 1 . . . . . . . . . 
. . 1 1 1 1 . . . . 1 1 1 1 . . . . . . 1 1 1 1 . . . . 1 1 1 1 1 . . . 1 1 1 1 . . . . . . . . . . 
. 1 1 1 1 . . . . . . 1 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 . . . 1 1 . 1 1 1 . . . . . . . . 
. . 1 1 1 1 . . . . 1 1 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 1 . . . 1 1 . 1 1 . . . 1 1 1 . 1 . 
. . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . . . 1 1 1 . . . . . 1 1 1 . . . . . 1 1 1 1 . 
. . . . . . . . . . 1 1 . 1 1 . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . 1 1 1 . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 1 . 
. 1 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 . 
. 1 1 1 1 1 . . . . . . . . . 1 . . . 1 1 1 . . . . . . . . . . 1 . . . 1 . 1 1 1 . . . 1 1 1 1 1 . 
. . 1 1 1 1 . . . . . . 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 . . . . 1 1 1 1 1 . . . . . . . . . 
. 1 1 1 1 . . . . . 1 1 1 1 1 . . . . 1 1 1 1 . . . . . . 1 1 1 1 . . . . 1 1 1 1 . . . . . . . . . 
. . 1 1 1 1 . . . . 1 1 1 . . . . . . 1 1 1 1 . . 1 . . 1 1 1 1 . . . . 1 1 1 1 . . . . . . . . . . 
. 1 1 1 1 . . . 1 . 1 1 1 1 . . . . . . 1 1 1 1 . . . . . 1 1 1 1 . . . 1 1 1 1 1 . . . . 1 1 1 1 . 
. . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . 1 1 1 1 . . . . . 1 1 1 . . 
. . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . 1 1 1 1 1 . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . 1 1 1 1 1 . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 1 . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
The document reading direction is vertical
Below is the input image overlay with bounding boxes
45 50 0 1
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 
. 9 1 1 1 1 . . . . . . . . . . . 1 . 1 1 1 1 1 . . . . . . . . . 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 1 1 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 1 1 . . . . . 1 1 . 1 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 . . . . . . 1 1 1 1 1 9 . . 9 . 1 1 1 . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . 1 1 1 1 . 9 . . 9 1 1 1 1 . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . 1 1 1 1 . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . . 1 1 1 . . . . . . . . . . . 9 . . 9 . . . . . . . . 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . 9 . . 9 1 1 1 . . . . . . . . 9 9 
. 9 1 1 1 1 . 1 . . 1 1 1 1 1 . . . . 1 1 1 1 . . . . 1 1 1 1 . 1 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 . . . . 1 1 1 1 1 9 . . 9 1 1 1 . . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . 1 1 1 . . 9 . . 9 1 1 1 . . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . . 1 1 1 . . . . . . . . . . . . . . 1 1 1 1 9 . . 9 . . . . . . . . 1 1 1 9 9 
. 9 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 1 . . . . 1 1 1 . . . . . . 1 1 1 1 1 9 . . 9 . 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 . 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 . . . . . 1 1 1 1 1 . . . . . 1 1 1 1 . . . . . 1 1 1 1 9 . . 9 1 1 1 . . . . 1 1 1 . 9 9 
. 9 . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . . 1 1 1 1 . 9 . . 9 . 1 1 1 . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9 . . 9 . . . . . . . . 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . 9 . . 9 1 . 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 . . . . . . 1 1 1 1 . . . . 1 1 1 1 1 9 . . 9 1 1 1 . . . . . . . . 9 9 
. 9 1 1 1 . . . . . . 1 1 1 1 . . . . 1 1 1 1 . . . . . 1 1 1 1 1 9 . . 9 1 . 1 1 1 . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 1 9 . . 9 1 . 1 1 . . . 1 1 1 . 9 9 
. 9 . . . . . . . . 1 1 1 1 1 . . . . . . . . . . . . . . 1 1 1 . 9 . . 9 1 1 1 . . . . . 1 1 1 9 9 
. 9 . . . . . . . . 1 1 . 1 1 . . . . . . . . . . . . . 1 1 1 1 . 9 . . 9 . . . . . . . 1 1 1 . 9 9 
. 9 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 . . . . . . . . . 9 . . 9 . . . . . . . . 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . . . . 1 . . . 1 1 1 . . . . . . . . . . 1 9 . . 9 . 1 1 1 . . . 1 1 1 1 9 9 
. 9 1 1 1 1 . . . . . . 1 1 1 . . . . . 1 1 1 1 . . . . 1 1 1 1 . 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 . . . . . 1 1 1 1 1 . . . . 1 1 1 1 . . . . . . 1 1 1 1 9 . . 9 1 1 1 1 . . . . . . . 9 9 
. 9 1 1 1 1 . . . . 1 1 1 . . . . . . 1 1 1 1 . . 1 . . 1 1 1 1 . 9 . . 9 1 1 1 . . . . . . . . 9 9 
. 9 1 1 1 . . . 1 . 1 1 1 1 . . . . . . 1 1 1 1 . . . . . 1 1 1 1 9 . . 9 1 1 1 1 . . . . 1 1 1 9 9 
. 9 . . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . 1 1 1 1 1 9 . . 9 1 1 1 . . . . . 1 1 1 9 9 
. 9 . . . . . . . . 1 1 1 1 . . . . . . . . . . . . . . . 1 1 1 1 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 . . . . . . . . . . . . . . . . . . . . . . . . . . 1 1 1 1 . 9 . . 9 . . . . . . . 1 1 1 1 9 9 
. 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
Output the boxNode in the list
2
2 37 43 50
"# text-line-detection" 
"# text-line-detection" 
"# text-line-detection" 
"# text-line-detection" 
