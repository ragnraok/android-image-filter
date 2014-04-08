package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.Paint;

public class BlockFilter {
	public static Bitmap changeToBrick(Bitmap mBitmap) {		     
		 int width = mBitmap.getWidth();
		 int height = mBitmap.getHeight();
		 
		 Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888); 
		 
		 int iPixel = 0;
		 for (int i = 0; i < width; i++) {
		       for (int j = 0;  j < height; j++) {
		         int currColor = mBitmap.getPixel(i,j);
		         
		         int avg = (Color.red(currColor) + Color.green(currColor) + Color.blue(currColor)) / 3;
		         if(avg >= 100)
		         {
		             iPixel = 255;    
		         } 
		         else {
		        	 iPixel = 0;
		         }            
		         returnBitmap.setPixel(i, j, Color.argb(255, iPixel, iPixel, iPixel));
		     }
		 }
	   
		 return returnBitmap;
	}
}
