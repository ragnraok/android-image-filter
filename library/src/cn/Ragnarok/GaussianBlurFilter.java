package cn.Ragnarok;

import android.graphics.Bitmap;

public class GaussianBlurFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToGaussianBlur(Bitmap bitmap, double sigma) {
		int ksize = (int) (sigma * 3 + 1);
		if (ksize == 1) {
			throw new IllegalArgumentException(String.format("sigma %f is too small", sigma));
		}
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.discreteGaussianBlur(pixels, width, height, sigma);
		Bitmap returnBitmap = Bitmap.createBitmap(returnPixels, width, height, Bitmap.Config.ARGB_8888);
		
		return returnBitmap;
	}
}
