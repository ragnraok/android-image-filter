package cn.Ragnarok;

import android.graphics.Bitmap;

public class TvFilter {
	
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static final Bitmap changeToTV(Bitmap bitmap) {
		int height = bitmap.getHeight();
		int width = bitmap.getWidth();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] resultPixels = NativeFilterFunc.tvFilter(pixels, width, height);
		returnBitmap.setPixels(resultPixels, 0, width, 0, 0, width, height);
		return returnBitmap;
	}
}
