package cn.Ragnarok;

import android.graphics.Bitmap;

public class HDRFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToHDR(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		int[] basicEffectPixels = NativeFilterFunc.hdrFilter(pixels, width, height);
		
		Bitmap basicEffectBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		basicEffectBitmap.setPixels(basicEffectPixels, 0, width, 0, 0, width, height);
		Bitmap returnBitmap = SharpenFilter.changeToSharpen(basicEffectBitmap);
		
		return returnBitmap;
	}
}
