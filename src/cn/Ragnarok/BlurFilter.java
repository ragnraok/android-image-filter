package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;

public class BlurFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	/*
	public static Bitmap changeToVague(Bitmap bitmap) {
		return changeToVague(bitmap, 10);
	}*/
	public static Bitmap changeToVague(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.averageSmooth(pixels, width, height);
		returnBitmap.setPixels(returnPixels, 0, width, 0, 0, width, height);
		
		return returnBitmap;
	}
}
