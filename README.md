android-image-filter
====================

some android image filters

in some filter, I use NDK to implement it

# Setup

- Install Android NDK and properly configure it: [http://goo.gl/koTCb](http://goo.gl/koTCb)
- Get a clean clone of this project, import the library in Ecliplse, click Project->Clean, then click Project->Build Project
to regenerate the library
- Then just add AndroidImageFilter as a dependency to your existing project.

# How to Use it

- It is dead simple, you can see magic in the following code:

```Java
  Bitmap newBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.BLUR_STYLE);
  imageView.setImageBitmap(newBitmap);
```

it is very simple, right? And you can see all filters in file [/src/cn/Ragnarok/BitmapFilter.java][3], it contains totally
17 kinds of filters now!

- Also, you can download the demo app from this [link][1]


If you have any question, please open an [issue][4] and show your code and the program ouput, thanks!

 ![][2]
 
# The MIT License (MIT)

Copyright (c) \<2012-2013\>  \<ragnarok okone1288@gmail.com\>

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

[1]: https://s.yunio.com/6bE4ny
[2]: http://i46.tinypic.com/263hff8.jpg
[3]: https://github.com/ragnraok/android-image-filter/blob/master/src/cn/Ragnarok/BitmapFilter.java
[4]: https://github.com/ragnraok/android-image-filter/issues?state=open

