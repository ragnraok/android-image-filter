package cn.Ragnarok;

import android.graphics.Bitmap;

public class GaussianBlurFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToGaussianBlur(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		int[] returnPixels = NativeFilterFunc.discreteGaussianBlur(pixels, width, height);
		returnBitmap.setPixels(returnPixels, 0, width, 0, 0, width, height);
		
		return returnBitmap;
	}
}
