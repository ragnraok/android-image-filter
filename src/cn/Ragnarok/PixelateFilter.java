package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;

public class PixelateFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static final Bitmap changeToPixelate(Bitmap bitmap, int pixelSize) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		int[] returnPixels = NativeFilterFunc.pxelateFilter(pixels, width, height, pixelSize);
		returnBitmap.setPixels(returnPixels, 0, width, 0, 0, width, height);
		
		return returnBitmap;
		
	}
}
