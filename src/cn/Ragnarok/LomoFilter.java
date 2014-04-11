package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;
import android.util.Log;

public class LomoFilter {
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToLomo(Bitmap bitmap, double roundRadius) {
		
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		Canvas canvas = new Canvas(returnBitmap);
		Paint paint = new Paint();
		paint.setAntiAlias(true);
		
		float scaleValue = 95 * 1.0F / 127;  
		
		ColorMatrix scaleMatrix = new ColorMatrix();
		scaleMatrix.reset();
		scaleMatrix.setScale((float) (scaleValue + 0.2), (float) (scaleValue + 0.4), (float)(scaleValue + 0.2), 1);
		
		ColorMatrix satMatrix = new ColorMatrix();
		satMatrix.reset();
		satMatrix.setSaturation(0.85f);
		
		ColorMatrix allMatrix = new ColorMatrix();
		allMatrix.reset();
		allMatrix.postConcat(scaleMatrix);
		allMatrix.postConcat(satMatrix);
		
		paint.setColorFilter(new ColorMatrixColorFilter(allMatrix));
		canvas.drawBitmap(bitmap, 0, 0, paint);
		
		int[] pixels = new int[width * height];
		returnBitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] resultPixels = NativeFilterFunc.lomoAddBlckRound(pixels, width, height, roundRadius);
		returnBitmap.setPixels(resultPixels, 0, width, 0, 0, width, height);
		
		return returnBitmap;
	}	
	
}
