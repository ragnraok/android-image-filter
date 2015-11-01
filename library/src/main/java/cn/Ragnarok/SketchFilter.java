package cn.Ragnarok;

import android.graphics.Bitmap;

public class SketchFilter {
	
	static {
		System.loadLibrary("AndroidImageFilter");
	}

	public static Bitmap changeToSketch(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.sketchFilter(pixels, width, height);
		Bitmap returnBitmap = Bitmap.createBitmap(returnPixels, width, height, Bitmap.Config.ARGB_8888);
		
		return returnBitmap;
		
	}

}
