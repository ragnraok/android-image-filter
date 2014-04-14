package cn.Ragnarok;

import android.graphics.Bitmap;

public class TvFilter {
	
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static final Bitmap changeToTV(Bitmap bitmap) {
		int height = bitmap.getHeight();
		int width = bitmap.getWidth();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] resultPixels = NativeFilterFunc.tvFilter(pixels, width, height);
		Bitmap returnBitmap = Bitmap.createBitmap(resultPixels, width, height, Bitmap.Config.ARGB_8888);
		
		return returnBitmap;
	}
}
