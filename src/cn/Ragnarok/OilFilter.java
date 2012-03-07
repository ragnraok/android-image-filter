package cn.Ragnarok;

import java.util.Random;

import android.graphics.Bitmap;

public class OilFilter {
	// 油画效果函数
	public static Bitmap changeToOil(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
		
		int color = 0;
		int radio = 0;
		
		Random random = new Random();
		int iModel = 4;
		int i = width - iModel;
		
		while (i > 1) { 
			int j = height - iModel;
			while (j > 1) {
				int iPos = random.nextInt(100000000) % iModel;
				color = bitmap.getPixel(i + iPos, j + iPos);
				returnBitmap.setPixel(i, j, color);
				j--;
			}
			i--;
		}
		
		return returnBitmap;
	}
}
