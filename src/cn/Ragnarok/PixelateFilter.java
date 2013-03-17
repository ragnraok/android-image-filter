package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;

public class PixelateFilter {
	private static int pixelSize = 10;
	private static int colorArray[];
	private static int width;
	private static int height;
	
	public static final Bitmap changeToPixelate(Bitmap bitmap) {
		int color;
		width = bitmap.getWidth();
		height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		
		colorArray = new int[width * height];
		bitmap.getPixels(colorArray, 0, width, 0, 0, width, height);
		
		for (int x = 0; x < width; x += pixelSize) {
			for (int y = 0; y < height; y +=pixelSize) {				
				color = getPredominantRGB(bitmap, x,y,pixelSize);
				fillRect(returnBitmap, x,y, pixelSize, color);					
			}
		}
		
		return returnBitmap;
	}
	
	private static int getPredominantRGB(Bitmap bitmap, int col, int row, int squareSize){
		int red = 0;
		int green = 0;
		int blue = 0;
		
		for(int x= col; x < col + squareSize; x++){
			for(int y = row; y < row + squareSize; y++){
				if(x < bitmap.getWidth() && y < bitmap.getHeight()) {	
					red += Color.red(colorArray[y * width + x]);
					green += Color.green(colorArray[y * width + x]);
					blue += Color.blue(colorArray[y * width + x]);
				}				
			} 
		}
		int val = (int) Math.pow(squareSize, 2);
		return Color.rgb(red / val, green / val, blue / val);
	}
	

	private static void fillRect(Bitmap bitmap, int col, int row, int squareSize, int color){
		for(int x = col; x < col + squareSize; x++){
			for(int y = row; y < row + squareSize; y++){
				if(x < bitmap.getWidth() && y < bitmap.getHeight()){
					bitmap.setPixel(x, y, color);
				}
			}
		}					
	}
}
