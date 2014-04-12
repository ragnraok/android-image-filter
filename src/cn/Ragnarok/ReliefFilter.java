package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;


public class ReliefFilter {
	
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	public static Bitmap changeToRelief(Bitmap bitmap) {        
//		 int mBitmapWidth = 0;
//		 int mBitmapHeight = 0;
//
//		 mBitmapWidth = mBitmap.getWidth();
//		 mBitmapHeight = mBitmap.getHeight();
//		 
//		 Bitmap bmpReturn = Bitmap.createBitmap(mBitmapWidth, mBitmapHeight, Bitmap.Config.ARGB_8888); 
//
//		 int  preColor = 0;
//		 preColor = mBitmap.getPixel(0,0);
//		        
//		 for (int i = 0; i < mBitmapWidth; i++) {
//		      for (int j = 0;  j < mBitmapHeight; j++) {
//		        int currColor = mBitmap.getPixel(i,j);
//		        int r = Color.red(currColor) - Color.red(preColor) + 128;
//		        int g = Color.green(currColor) - Color.red(preColor) + 128;
//		        int b = Color.green(currColor) - Color.blue(preColor) + 128;
//		        int a = Color.alpha(currColor);
//		        int modifyColor  = Color.argb(a, r, g, b);
//		        bmpReturn.setPixel(i, j, modifyColor);
//		        preColor = currColor;
//		    }
//		}
//		        
//		Canvas c = new Canvas(bmpReturn);
//		Paint paint = new Paint();
//		ColorMatrix cm = new ColorMatrix();
//		cm.setSaturation(0);
//		ColorMatrixColorFilter f = new ColorMatrixColorFilter(cm);
//		paint.setColorFilter(f);
//		c.drawBitmap(bmpReturn, 0, 0, paint);
//		return bmpReturn;
		
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		int[] returnPixels = NativeFilterFunc.reliefFilter(pixels, width, height);
		returnBitmap.setPixels(returnPixels, 0, width, 0, 0, width, height);
		
		// set the saturation
//		Canvas c = new Canvas(returnBitmap);
//		Paint paint = new Paint();
//		ColorMatrix cm = new ColorMatrix();
//		cm.setSaturation(0);
//		ColorMatrixColorFilter f = new ColorMatrixColorFilter(cm);
//		paint.setColorFilter(f);
//		c.drawBitmap(returnBitmap, 0, 0, paint);
		
		return returnBitmap;
	}
		
	
}
