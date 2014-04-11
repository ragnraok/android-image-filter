package cn.Ragnarok;

import android.graphics.Bitmap;
import android.util.Log;

public class LightFilter {
	
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToLight(Bitmap bitmap, int centerX, int centerY, int radius) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.lightFilter(pixels, width, height, centerX, centerY, radius);
		
		Log.d("AndroidImageFilter", "returnPixels[1] = " + returnPixels[1]);
		returnBitmap.setPixels(returnPixels, 0, width, 0, 0, width, height);
		
		return returnBitmap;
	}
}
