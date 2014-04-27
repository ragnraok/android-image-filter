package cn.Ragnarok;

import java.util.Random;

import android.graphics.Bitmap;

public class OilFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToOil(Bitmap bitmap, int oilRange) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.oilFilter(pixels, width, height, oilRange);
		Bitmap returnBitmap = Bitmap.createBitmap(returnPixels, width, height, Bitmap.Config.ARGB_8888);
		return returnBitmap;
	}
}
