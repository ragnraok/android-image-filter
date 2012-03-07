package cn.Ragnarok;

import android.graphics.Bitmap;

public class TvFilter {
	
	// 电视效果函数
	public static final Bitmap changeToTV(Bitmap bitmap) {
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
			for (int y = 0; y < height; y+=3) {
				
				r=0;
				g=0;
				b=0;
					
				for(int w=0; w<3; w++){
					if(y+w < height ){
						r += ((colorArray[(((y+w)*width+x))]& 0x00FF0000) >>> 16) / 2;
						//r += (imageIn.getRComponent(x, y+w))/2;
						g += ((colorArray[(((y+w)*width+x))]& 0x0000FF00) >>> 8) / 2;
						//g += (imageIn.getGComponent(x, y+w))/2;
						b += (colorArray[(((y+w)*width+x))] & 0x000000FF) / 2;
						//b += (imageIn.getBComponent(x, y+w))/2;						
					}
				}
				r = getValidInterval(r);
				g = getValidInterval(g);
				b = getValidInterval(b);
						
				for(int w=0; w<3; w++){
					if(y+w < height){
						if(w == 0){
							colorArray[(((y+w)*width+x))] = (255 << 24) + (r << 16) + (0 << 8) + 0;
							returnBitmap.setPixel(x, y+w, colorArray[(((y+w)*width+x))]);
							//returnBitmap.setPixelColour(x,y+w,r,0,0);
						}
						else if(w ==1){
							colorArray[(((y+w)*width+x))] = (255 << 24) + (0 << 16) + (g << 8) + 0;
							returnBitmap.setPixel(x, y+w, colorArray[(((y+w)*width+x))]);
							//imageIn.setPixelColour(x,y+w,0,g,0);
						}
						else if(w==2){
							colorArray[(((y+w)*width+x))] = (255 << 24) + (0 << 16) + (0 << 8) + b;
							returnBitmap.setPixel(x, y+w, colorArray[(((y+w)*width+x))]);
							//imageIn.setPixelColour(x,y+w,0,0,b);
						}
					}
				}				
			}
		}
		
		return returnBitmap;
	}
	
	/**
	 * method to calculate an appropriate interval for flicker lines
	 * 
	 * @param a_value
	 * @return
	 */
	private static int getValidInterval(int a_value){
		if(a_value < 0) return 0;
		if(a_value > 255) return 255;
		return a_value;
	}
}
