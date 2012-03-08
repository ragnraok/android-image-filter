package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;
import android.util.Log;

public class LomoFilter {
	
	public static Bitmap changeToLomo(Bitmap bitmap) {
		
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
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
		
		ColorMatrix hueMatrix = new ColorMatrix();
		hueMatrix.reset();
		hueMatrix.setRotate(0, 5);
		hueMatrix.setRotate(1, 5);
		hueMatrix.setRotate(2, 5);
		
		ColorMatrix allMatrix = new ColorMatrix();
		allMatrix.reset();
		allMatrix.postConcat(scaleMatrix);
		allMatrix.postConcat(satMatrix);
		//allMatrix.postConcat(hueMatrix);
		
		paint.setColorFilter(new ColorMatrixColorFilter(allMatrix));
		canvas.drawBitmap(bitmap, 0, 0, paint);
		
		double radius = (double) (width / 2) * 95 / 100;
		double centerX = width / 2f;
		double centerY = height / 2f;
		
		int pixels[] = new int[width * height];
		returnBitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int currentPos;
		
		double pixelsFalloff = 3.5;
		
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				double dis = Math.sqrt(Math.pow((centerX - x), 2) + Math.pow(centerY - y, 2));
				currentPos = y * width + x;
				
				if (dis > radius) {
						int pixR = Color.red(pixels[currentPos]);
						int pixG = Color.green(pixels[currentPos]);
						int pixB = Color.blue(pixels[currentPos]);
						
						double scaler = scaleFunction(radius, dis, pixelsFalloff);
						
						scaler = Math.abs(scaler);
						Log.d("Ragnarok", "scaler=" + scaler);
						
						int newR = (int) (pixR - scaler);
						int newG = (int) (pixG - scaler);
						int newB = (int) (pixB - scaler);
						
						//Log.d("Ragnarok", "newR=" + newR + ", newG=" + newG + ", newB=" + newB);
						
						newR = Math.min(255, Math.max(0, newR));
						newG = Math.min(255, Math.max(0, newG));
						newB = Math.min(255, Math.max(0, newB));
						
						//Log.d("Ragnarok", "x=" + x + ", y=" + y);
						//Log.d("Ragnarok", "newR=" + newR + ", newG=" + newG + ", newB=" + newB);
						
						pixels[currentPos] = Color.argb(255, newR, newG, newB);
						
						
				}
			}
		}
		
		returnBitmap.setPixels(pixels, 0, width, 0, 0, width, height);
		
		
		return returnBitmap;
	}
	 
	private static double scaleFunction(double radius, double dis, double pixelsFallof) {
		return 1 - Math.pow((double)((dis - radius) / pixelsFallof), 2);
	}	
	
}
