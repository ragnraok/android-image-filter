package cn.Ragnarok;

import android.graphics.Bitmap;

public class InvertFilter {
	// 反色效果函数
	public static Bitmap chageToInvert(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
		
		int colorArray[] = new int[width * height];
		int r, g, b;
		bitmap.getPixels(colorArray, 0, width, 0, 0, width, height);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int index = y * width + x;
				r = (colorArray[index] >> 16) & 0xff;
				g = (colorArray[index] >> 8) & 0xff;
				b = colorArray[index] & 0xff;
				colorArray[index] = 0xff000000 | (r << 16) | (g << 8) | b;
			}
		}
		
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				r = (255-(int)(colorArray[((y*width+x))]& 0x00FF0000) >>> 16);
				g = (255-(int)(colorArray[((y*width+x))]& 0x0000FF00) >>> 8);
				b = (255-(int)(colorArray[((y*width+x))] & 0x000000FF));
				
				colorArray[((y*width+x))] = (255 << 24) + (r << 16) + (g << 8) + b;
				returnBitmap.setPixel(x, y, colorArray[((y*width+x))]);
			}
		}
		
		return returnBitmap;
		
	}
}
