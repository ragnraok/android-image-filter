package cn.Ragnarok;

import android.graphics.Bitmap;

public class MotionBlurFilter {

	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToMotionBlur(Bitmap bitmap, int xSpeed, int ySpeed) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.motionBlurFilter(pixels, width, height, xSpeed, ySpeed);
		Bitmap returnBitmap = Bitmap.createBitmap(returnPixels, width, height, Bitmap.Config.ARGB_8888);
		return returnBitmap;
	}
}
