android-image-filter
====================

some android image filters

in some filter, I use NDK to implement to make it more efficient

# Setup

- Install Android NDK and properly configure it: [http://goo.gl/koTCb](http://goo.gl/koTCb)
- Get a clean clone of this project, import the library in Android Studio
- then Clean and Build the hold project to regenerate the library
- Then just add library module as a dependency to your existing project.

# How to Use it
It is dead simple, you can see magic in the following code:

```Java
  Bitmap newBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.BLUR_STYLE);
  imageView.setImageBitmap(newBitmap);        
```

and there are some options for the filter, you can go to see the demo to see how to use this options to customize your filter effect

You can see all filters in file [BitmapFilter.java][3], currently contains totally 19 kinds of filters now, here is the list of filters and their options(show by code):

* Grayscale
* Relief
* Blur(Average Smooth)

	```Java
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.BLUR_STYLE, maskSize);
	```
	
``maskSize`` is a integer, to indicate the average blur mask's size
	
* Oil Painting
* Neon
	
	```Java
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.NEON_STYLE, 
	neon_color_R, neon_color_G, neon_color_B);	
	```

``neon_color_R``, ``neon_color_G``, ``neon_color_B`` are the R,G,B component are integer	
	
* Pixelate
	
	```Java 
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.PIXELATE_STYLE, pixelSize);
	```
	
``pixelSize`` is a integer, the pixel size for this filter
	
* Old TV
* Invert Color
* Block
* Old Photo
* Sharpen(By Laplacian)
* Light
	
	```Java 
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.LIGHT_STYLE, light_center_x, light_center_y, light_radius);
	```
	
``light_center_x``, ``light_center_y`` are integer, indicate the center of the light spot, the origin in the left-upper side, and the ``light_radius`` is indicate the radius of light spot, in pixel

* Lomo
	
	```Java
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.LOMO_STYLE, roundRadius);
	```

``roundRadius`` is a double, the black round's radius in the effect	

* HDR
* Gaussian Blur

	```Java
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.GAUSSIAN_BLUR_STYLE, sigma);
	```
	
	``sigma`` is a double, the sigma value in Gaussian Blur, the bigger of sigma, the smoother in the result image

* Soft Glow

	```Java
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.SOFT_GLOW_STYLE, sigma);
	```
	
	``sigma`` is a double, the same as ``sigma`` in Gaussian Blur, indicate the sigma value in the process of Gaussian Blur for Soft Glow

* Sketch
* Motion Blur

	```Java
	BitmapFilter.changeStyle(originBitmap, BitmapFilter.SOFT_GLOW_STYLE, xSpeed, ySpeed);
	```
	``xSpeed`` and ``ySpeed`` are both integer, indicate the speed in x-axis and y-axis, the origin in the left-upper side

* Gotham

PS: all options have defalut values, so you can just select the effect and pass nothing, like this:

```Java
BitmapFilter.changeStyle(originBitmap, BitmapFilter.MOTION_BLUR_STYLE);
```


Also, you can download the demo app from this [link][1]


If you have any question, please open an [issue][4] and show your code and the program ouput, thanks!

 ![][2]
 
# The MIT License (MIT)

Copyright (c) \<2012-2014\>  \<ragnarok okone1288@gmail.com\>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

[1]: http://1drv.ms/1i10uuX
[2]: screenshot/img1.png
[3]: library/src/cn/Ragnarok/BitmapFilter.java
[4]: https://github.com/ragnraok/android-image-filter/issues?state=open

