package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.Paint;

public class BlockFilter {
	// 版画效果函数
	public static Bitmap changeToBrick(Bitmap mBitmap) {
		 Paint mPaint;
	     
		 int mBitmapWidth = 0;
		 int mBitmapHeight = 0;
		     
		 int mArrayColor[] = null;
		 int mArrayColorLengh = 0;
		 long startTime = 0;
		 int mBackVolume = 0;
		     
		 mBitmapWidth = mBitmap.getWidth();
		 mBitmapHeight = mBitmap.getHeight();
		 
		 Bitmap bmpReturn = Bitmap.createBitmap(mBitmapWidth, mBitmapHeight, Bitmap.Config.ARGB_8888); 
		    
		 mArrayColorLengh = mBitmapWidth * mBitmapHeight;   
		    
		 int count = 0;
		 int  preColor = 0;
		 int color = 0;
		 int iPixel = 0;
		 for (int i = 0; i < mBitmapWidth; i++) {
		       for (int j = 0;  j < mBitmapHeight; j++) {
		         int curr_color = mBitmap.getPixel(i,j);
		         
		         int avg = ( Color.red(curr_color) + Color.green(curr_color) + Color.blue(curr_color))/3 ;
		         if(avg >= 100)
		         {
		             iPixel = 255;    
		         } 
		         else {
		        	 iPixel = 0;
		         }    
		         int modif_color = Color.argb(255, iPixel, iPixel, iPixel);
		            
		         bmpReturn.setPixel(i, j, modif_color);
		     }
		 }
		    
		   
		 return bmpReturn;
	}
}
