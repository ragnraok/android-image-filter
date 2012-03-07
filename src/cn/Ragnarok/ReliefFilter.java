package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;

public class ReliefFilter {
	// 浮雕效果函数
	public static Bitmap changeToRelief(Bitmap mBitmap) {
		 Paint mPaint;
	         
		 int mBitmapWidth = 0;
		 int mBitmapHeight = 0;
		         
		 int mArrayColor[] = null;
		 int mArrayColorLengh = 0;
		 long startTime = 0;
		 int mBackVolume = 0;
		        
		 mBitmapWidth = mBitmap.getWidth();
		 mBitmapHeight = mBitmap.getHeight();
		 
		 Bitmap bmpReturn = Bitmap.createBitmap(mBitmapWidth, mBitmapHeight, Bitmap.Config.RGB_565); 
		 mArrayColorLengh = mBitmapWidth * mBitmapHeight;   

		 int count = 0;
		 int  preColor = 0;
		 int  prepreColor = 0;
		 int color = 0;
		 preColor = mBitmap.getPixel(0,0);
		        
		 for (int i = 0; i < mBitmapWidth; i++) {
		      for (int j = 0;  j < mBitmapHeight; j++) {
		        int curr_color = mBitmap.getPixel(i,j);
		        int r = Color.red(curr_color) - Color.red(prepreColor) +128;
		        int g = Color.green(curr_color) - Color.red(prepreColor) +128;
		        int b = Color.green(curr_color) - Color.blue(prepreColor) +128;
		        int a = Color.alpha(curr_color);
		        int modif_color  = Color.argb(a, r, g, b);
		        bmpReturn.setPixel(i, j, modif_color);
		        prepreColor = preColor;
		        preColor = curr_color;
		    }
		}
		        
		Canvas c = new Canvas(bmpReturn);
		Paint paint = new Paint();
		ColorMatrix cm = new ColorMatrix();
		cm.setSaturation(0);
		ColorMatrixColorFilter f = new ColorMatrixColorFilter(cm);
		paint.setColorFilter(f);
		c.drawBitmap(bmpReturn, 0, 0, paint);
		return bmpReturn;
			
	}
}
